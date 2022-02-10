/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"

#include <QLabel>
#include <QMessageBox>

//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    // 멤버변수 생성
    m_ui(new Ui::MainWindow),   // ui 생성
    m_status(new QLabel),   // 상태 생성
    m_console(new Console),     // 콘솔 생성
    m_settings(new SettingsDialog),     // (다이어로그)세팅 생성
//! [1]
    m_serial(new QSerialPort(this))     // 시리얼(포트) 생성
//! [1]
{
//! [0]
    m_ui->setupUi(this);    // UI 셋업
    m_console->setEnabled(false);   // 활성화 설정
    setCentralWidget(m_console);    // 콘솔 멤버변수 위젯 설정

    m_ui->actionConnect->setEnabled(true);  // ui 멤버변수에서 연결동작에 대한 활성화를 설정
    m_ui->actionDisconnect->setEnabled(false);  // ui 멤버변수에서 비연결동작에 대한 활성화를 설정
    m_ui->actionQuit->setEnabled(true); // ui 멤버변수에서 해제동작에 대한 활성화를 설정
    m_ui->actionConfigure->setEnabled(true);    // ui 멤버변수에서 구성동작에 대한 활성화를 설정

    m_ui->statusBar->addWidget(m_status);   // ui 멤버변수에서 상태 바에 위젯 추가

    initActionsConnections();   // 초기화 동작들 연결함

    // 멤버변수 시리얼에서 시그널 발생, 에러발생 시그널 발생, this에서 슬롯 발생, 핸들에러 슬롯 발생
    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);

//! [2]
    // 멤버변수 시리얼에서 시그널 발생, 읽기준비 시그널 발생, this에서 슬롯 발생, 읽기데이터 슬롯 발생
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//! [2]
    // 멤버변수 콘솔에서 시그널 발생, 받은데이터 시그널 발생, this에서 슬롯 발생, 쓰기데이터 슬롯 발생
    connect(m_console, &Console::getData, this, &MainWindow::writeData);
//! [3]
}
//! [3]

// 소멸자
MainWindow::~MainWindow()
{
    delete m_settings;  // 세팅 멤버변수 삭제
    delete m_ui;    // ui 멤버변수 삭제
}

//! [4]
void MainWindow::openSerialPort()   //시리얼포트 오픈
{
    const SettingsDialog::Settings p = m_settings->settings();  // p는 멤버변수 세팅에 세팅할 것들이다.
    m_serial->setPortName("COM5"); // 포트 이름 설정
    m_serial->setBaudRate(9600); // 보드레이트 설정
    m_serial->setDataBits(p.dataBits); // 데이터 비트 설정
    m_serial->setParity(p.parity); // 패리티 설정
    m_serial->setStopBits(p.stopBits); // 스탑 비트 설정
    m_serial->setFlowControl(p.flowControl); // 플로우 컨트롤 설정
    if (m_serial->open(QIODevice::ReadWrite)) { //읽고 쓰기 모드로 염
        m_console->setEnabled(true);    // 활성화 설정
        m_console->setLocalEchoEnabled(p.localEchoEnabled); // 지역 에코 활성화를 설정
        m_ui->actionConnect->setEnabled(false); // 동작 연결에 활성화 설정
        m_ui->actionDisconnect->setEnabled(true);   // 동작 비연결에 활설화 설정
        m_ui->actionConfigure->setEnabled(false);   // 동작 구성에 활성화 설정
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")    // 상태메세지를 보여줌
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)  // (상태메세지에)포트이름, 문자열보드레이트, 문자열데이터비트 출력
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl)); // +) 문자패리티, 문자스탑비트, 문자플로우컨드롤 출력
    } else { // 시리얼포트가 안열렸다면
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());  // 충돌에 대한 에러메세지박스 띄움

        showStatusMessage(tr("Open error"));    // 싱태메세지 보여줌(여는데 에러가 났다는)
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()  // 시리얼포트를 닫을 떄
{
    if (m_serial->isOpen()) // 멤버변수 시리얼이 열려 있을 ㄸㅐ
        m_serial->close();  // 멤버변수 시리얼을 닫음
    m_console->setEnabled(false);   // 멤버변수 콘솔에 활성화 설정
    m_ui->actionConnect->setEnabled(true);  // 멤버변수 ui에 동작연결에 활성화 설정
    m_ui->actionDisconnect->setEnabled(false);  // 멤버변수 ui에 비연결동작에 활성화 설정
    m_ui->actionConfigure->setEnabled(true);    // 멤버변수 ui에 구성동작에 활성화 설정
    showStatusMessage(tr("Disconnected"));  // 상태메세지를 보여준다(Disconnected 띄움)
}
//! [5]

void MainWindow::about()    // about 함수
{
    QMessageBox::about(this, tr("About Simple Terminal"),   // 터미널 사용방법에 대한 메세지박스 출력
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)  // 쓰기데이터 함수
{
    m_serial->write(data);  //멤버변수 시리얼에 데이터를 작성
}
//! [6]

//! [7]
void MainWindow::readData() // 읽기데이터 함수
{
    const QByteArray data = m_serial->readAll();    // 데이터는 멤버변수 시리얼에서 모든 것을 읽어 온 것
    // 앞으로 해야할 일 ! 현재는 그냥 값이 콘솔창에 보여지는 거지만, 이걸 !!!차트에 뿌려 주기!!!
    m_console->putData(data);   // 멤버변수 콘솔에 데이터를 뿌림
}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)    // 핸들에러 함수(시리얼포트에러)
{
    if (error == QSerialPort::ResourceError) {  // 시리얼포트의 리소스에러라면,
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString()); // 충돌 에러 발생 메세지 박스 띄움
        closeSerialPort();  // 시리얼포트 닫음
    }
}
//! [8]

void MainWindow::initActionsConnections()   // 초기화 동작 연결 함수
{
    // 멤버변수 ui에서 동적연결에서 시그널 발생, 트리거 시그널 발생, this에서 슬롯 발생, 오픈시리얼포트 슬롯 발생
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    // 멤버변수 ui에서 비연결동작에서 시그널 발생, 트리거 시그널 발생, this에서 슬롯 발생, 닫기시리얼포트 슬롯 발생
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    // 멤버변수 ui에서 그만둠동작에서 시그널 발생, 트리거 시그널 발생, this에서 슬롯 발생, 닫기 슬롯 발생
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    // 멤버변수 ui에서 동작구성에서 시그널 발생, 트리거 시그널 발생, 멤버변수 설정에서 슬롯 발생, show 슬롯 발생
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    // 멤버변수 ui에서 동작비우기에서 시그널 발생, 트리거 시그널 발생, 멤버변수 설정에서 슬롯 발생, clear 슬롯 발생
    connect(m_ui->actionClear, &QAction::triggered, m_console, &Console::clear);
    // 멤버변수 ui에서 설정동작에서 시그널 발생, 트리거 시그널 발생, this에서 슬롯 발생, about 슬롯 발생
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    // 멤버변수 ui에서 설정동작Qt에서 시그널 발생, 트리거 시그널 발생, qApp 시그널 발생, aboutQt 슬롯 발생
    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}


void MainWindow::showStatusMessage(const QString &message)  // 상태메세지 보여주는 함수
{
    m_status->setText(message);     // 멤버변수 상태에 메세지를 넣어서 출력
}
