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

#ifndef QPrabhupadaAboutWindow_H
#define QPrabhupadaAboutWindow_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QPrabhupada.h>
#include <QPrabhupadaDictionary.h>

class QPrabhupadaAboutDialog : public QStorageDialog
{
  CS_OBJECT( QPrabhupadaAboutDialog )

  public:
  QPrabhupadaAboutDialog() = delete;
  QPrabhupadaAboutDialog( QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags() );
  ~QPrabhupadaAboutDialog();
    virtual void LoadFromStream( QDataStream &ST );
    virtual void SaveToStream( QDataStream &ST );
  private:
    using inherited = QStorageDialog;
  protected:
    void changeEvent( QEvent *event ) override;
  public:
    QVBoxLayout *verticalLayoutPrabhupada;
    QVBoxLayout *verticalLayoutRowNumber;
    QFormLayout *formLayout;
    //QLabel *LabelRowNumber;
    //QComboBox *ComboBoxRowNumber;
    QTabWidget *TabWidgetAbout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PushButtonGo;
    QPushButton *PushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi( QDialog *QPrabhupadaAboutWindow );
    void retranslateUi( QDialog *QPrabhupadaAboutWindow );
};

class QStoragerPrabhupadaAboutDialog : public QStoragerDialog
{
  public:
    QStoragerPrabhupadaAboutDialog();
    ~QStoragerPrabhupadaAboutDialog();
  private:
    using inherited = QStoragerDialog;
  public:
    virtual void LoadFromStream( QObject *AObject, QDataStream &ST ) override;
    virtual void SaveToStream( QObject *AObject, QDataStream &ST ) override;
};

#endif
