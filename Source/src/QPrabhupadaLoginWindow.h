/***********************************************************************
*
* Copyright (c) 2022-2022 Navadvipa Chandra dasa
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#ifndef QPrabhupadaLoginWindow_H
#define QPrabhupadaLoginWindow_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QPrabhupada.h>
#include <QPrabhupadaDictionary.h>

class QPrabhupadaLoginDialog : public QDialog
{
  CS_OBJECT( QPrabhupadaLoginDialog )

  public:
    QPrabhupadaLoginDialog( QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags() ) = delete;
    QPrabhupadaLoginDialog() = delete;
    QPrabhupadaLoginDialog( QPrabhupadaDictionary *APrabhupadaDictionary
                          , QWidget *parent = nullptr
                          , Qt::WindowFlags flags = Qt::WindowFlags() );
    ~QPrabhupadaLoginDialog();
    //Ui::QPrabhupadaLoginDialog *m_ui = new Ui::QPrabhupadaLoginDialog;
    QString m_DriverName;
    QString m_Schema;
    QPrabhupadaDictionary *m_PrabhupadaDictionary = nullptr;
    bool Connect( QSqlDatabase *DB );
  private:
    using inherited = QDialog;
    void Connects();
    void Emits();
    void SQLRadioButton( bool checked );
    void DatabaseToWidget( QSqlDatabase *DB );
    void WidgetToDatabase( QSqlDatabase *DB );
    void LanguageUI_IndexChanged( int Value );
    void pushButtonOKClicked();
    void pushButtonCancelClicked();
  protected:
    void changeEvent( QEvent *event ) override;
  public:
    virtual void LoadFromStream( QDataStream &ST );
    virtual void SaveToStream( QDataStream &ST );

    QVBoxLayout *LayoutPrabhupadaLogin;
    QHBoxLayout *LayoutSQL;
    QRadioButton *radioButtonSQLite;
    QRadioButton *radioButtonPostgreSQL;
    QFormLayout *LayoutConnection;
    QLabel *LabelUserName;
    QComboBox *ComboBoxUserName;
    QLabel *LabelPassword;
    QLineEdit *LineEditPassword;
    QLabel *LabelDatabaseName;
    QComboBox *ComboBoxDatabaseName;
    QLabel *LabelHostName;
    QComboBox *ComboBoxHostName;
    QLabel *LabelPort;
    QComboBox *ComboBoxPort;
    QLabel *LabelSchema;
    QComboBox *ComboBoxSchema;
    QCheckBox *CheckBoxResetSettings;
    QLabel *LabelLanguageUI;
    QComboBox *ComboBoxLanguageUI;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *QPrabhupadaLoginDialog);
    void retranslateUi(QDialog *QPrabhupadaLoginDialog);
};

class QStoragerPrabhupadaLoginDialog : public QStoragerDialog
{
  public:
    QStoragerPrabhupadaLoginDialog();
    virtual ~QStoragerPrabhupadaLoginDialog();
  private:
    using inherited = QStoragerDialog;
  public:
    virtual void LoadFromStream( QObject *AObject, QDataStream &ST );
    virtual void SaveToStream( QObject *AObject, QDataStream &ST );
};

#endif
