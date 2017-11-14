#ifndef PINYINEDITOR_H
#define PINYINEDITOR_H

#include <QMainWindow>
#include <QApplication>
#include <QCloseEvent>
#include <QTimerEvent>
#include <QSaveFile>
#include <QScopedPointer>
#include <QTimer>

#include "ui_pinyin_editor.h"


static const int UPDATE_DELAY = 150; // 0.15s


class PinyinEditor : public QMainWindow
{
    Q_OBJECT

public:
    PinyinEditor(QWidget *parent = Q_NULLPTR);

public slots:
	void updateText();
	void onTextChanged();
	void deleteSelectedText();
	void newFile();
	void openFile();
	void saveFile();
	void saveAsFile();
	void saveOutput();
	void selectFont();
	void selectColor();
	void about();

private:
    Ui::PinyinEditorClass ui;
	QTimer updateTimer;
	bool saved;
	QScopedPointer<QSaveFile> currentFile;

protected:
	virtual void closeEvent(QCloseEvent *event);
	bool askSaveOrContinue();
};

#endif