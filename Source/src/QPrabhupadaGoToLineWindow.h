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

#ifndef QPrabhupadaGoToLineWindow_H
#define QPrabhupadaGoToLineWindow_H

#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QPrabhupada.h>
#include <QPrabhupadaDictionary.h>

class QPrabhupadaGoToLineDialog : public QDialog
{
  CS_OBJECT( QPrabhupadaGoToLineDialog )

  public:
    QPrabhupadaGoToLineDialog()                                                  = delete;
    QPrabhupadaGoToLineDialog( const QPrabhupadaGoToLineDialog& A )              = delete;
    QPrabhupadaGoToLineDialog( QPrabhupadaGoToLineDialog&& A )                   = delete;
    QPrabhupadaGoToLineDialog& operator = ( const QPrabhupadaGoToLineDialog& A ) = delete;
    QPrabhupadaGoToLineDialog& operator = ( QPrabhupadaGoToLineDialog&& A )      = delete;
    QPrabhupadaGoToLineDialog( QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags() );
    virtual ~QPrabhupadaGoToLineDialog();
    QStorage *m_Storage;

    CS_SIGNAL_1( Public, void SignalGoToLine( int Value ) )
    CS_SIGNAL_2( SignalGoToLine, Value )

  private:
    using inherited = QDialog;
    void PushButtonGoClicked();
    void PushButtonCancelClicked();
  protected:
    void changeEvent( QEvent *event ) override;
  public:
    QVBoxLayout *verticalLayoutPrabhupada;
    QVBoxLayout *verticalLayoutRowNumber;
    QFormLayout *formLayout;
    QLabel *LabelRowNumber;
    QComboBox *ComboBoxRowNumber;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PushButtonGo;
    QPushButton *PushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi( QDialog *QPrabhupadaGoToLineWindow );
    void retranslateUi( QDialog *QPrabhupadaGoToLineWindow );
};

class QStoragerPrabhupadaGoToLineDialog : public QStoragerDialog
{
  public:
    QStoragerPrabhupadaGoToLineDialog();
    virtual ~QStoragerPrabhupadaGoToLineDialog();
  private:
    using inherited = QStoragerDialog;
  public:
    virtual void LoadFromStream( void *AObject, QDataStream &ST ) override;
    virtual void SaveToStream(   void *AObject, QDataStream &ST ) override;
};

#endif
