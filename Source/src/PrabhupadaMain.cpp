/***********************************************************************
*
* Copyright (c) 2012-2022 Barbara Geller
* Copyright (c) 2012-2022 Ansel Sermersheim
* Copyright (c) 2015 The Qt Company Ltd.
*
* This file is part of KitchenSink.
*
* KitchenSink is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <QPrabhupadaLoginWindow.h>
#include <QPrabhupadaDictionaryWindow.h>

#include <QApplication>
#include <QPrabhupada.h>

int main( int argc, char *argv[] )
{
  int Result = 0;
  QClassicLog::StartLog( "Prabhupada.log" );
  QApplication a(argc, argv);

  QStorageDB AStorage;

  QPrabhupadaDictionary APrabhupadaDictionary( nullptr );
  APrabhupadaDictionary.setObjectName( "PrabhupadaDictionary" );
  APrabhupadaDictionary.m_Storage = &AStorage;
  a.setObjectName( APrabhupadaDictionary.objectName() );

  LoadObject< QStoragerLanguageVector >( &APrabhupadaDictionary.m_LanguageVector, &AStorage, QStorageKind::File, "m_LanguageVector.ini" );
  LoadObject< QStoragerLanguageIndex >( &APrabhupadaDictionary.m_LanguageUIIndex, &AStorage, QStorageKind::File );

  QPrabhupadaLoginDialog *APrabhupadaLoginDialog = new QPrabhupadaLoginDialog( &APrabhupadaDictionary, nullptr, Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint );

  APrabhupadaLoginDialog->ComboBoxUserName->    setEditText( "Navadvipa Chandra das" );
  APrabhupadaLoginDialog->ComboBoxDatabaseName->setEditText( "NewNavadvipa" );
  APrabhupadaLoginDialog->ComboBoxHostName->    setEditText( "127.0.0.1" );
  APrabhupadaLoginDialog->ComboBoxPort->        setEditText( QString::number( 5432 ) );
  APrabhupadaLoginDialog->ComboBoxSchema->      setEditText( "\"NewNavadvipa\"" );

  LoadObject< QStoragerPrabhupadaLoginDialog >( APrabhupadaLoginDialog, &AStorage, QStorageKind::File );
  APrabhupadaDictionary.m_LanguageUIIndex.PrepareComboBox( APrabhupadaLoginDialog->ComboBoxLanguageUI );

  int R, N = 0;
  while ( ++N < 4 ) {
     R = APrabhupadaLoginDialog->exec();
    if ( R == QDialog::Accepted ) {
      QSqlDatabase DB = QSqlDatabase::addDatabase( APrabhupadaLoginDialog->m_DriverName, "PrabhupadaDB" );
      if ( APrabhupadaLoginDialog->Connect( &DB ) ) {
        // Prepare AStorage
        AStorage.SetDatabase( &DB );
        AStorage.m_Schema = APrabhupadaLoginDialog->m_Schema;
        // Prepare APrabhupadaDictionary
        APrabhupadaDictionary.m_DB = &DB;
        APrabhupadaDictionary.m_Schema = AStorage.m_Schema;
        // Reset settings in DB, if need!
        if ( APrabhupadaLoginDialog->CheckBoxResetSettings->isChecked() ) {
            AStorage.ResetSettings();
        }
        LoadObject< QStoragerPrabhupadaDictionary >( &APrabhupadaDictionary, &AStorage, QStorageKind::DB );
        QPrabhupadaDictionaryWindow APrabhupadaDictionaryWindow = QPrabhupadaDictionaryWindow( &APrabhupadaDictionary );
        APrabhupadaDictionaryWindow.m_StorageKind = QStorageKind::DB;
        APrabhupadaDictionaryWindow.m_Storage = &AStorage;
        APrabhupadaDictionaryWindow.PrepareDictionary();
        LoadObject< QStoragerPrabhupadaDictionaryWindow >( &APrabhupadaDictionaryWindow, &AStorage, APrabhupadaDictionaryWindow.m_StorageKind );
        APrabhupadaDictionaryWindow.FirstShow();
        SaveObject< QStoragerPrabhupadaLoginDialog >( APrabhupadaLoginDialog, &AStorage, QStorageKind::File );

        delete APrabhupadaLoginDialog;
        APrabhupadaLoginDialog = nullptr;

        Result = a.exec();
        break;
      }
    } else {
      break;
    }
  }
  if ( APrabhupadaLoginDialog ) {
    delete APrabhupadaLoginDialog;
  }
  QClassicLog::FinishLog();
  return Result;
}
