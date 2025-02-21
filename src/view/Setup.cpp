#include "Setup.h"
#include "ui_Setup.h"

#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QChar>
#include <QMap>
#include <QProcess>
#include <QSettings>

Setup::Setup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Setup)
{
    ui->setupUi(this);

    // 连接按钮的点击事件到恢复默认槽函数
    connect(ui->RestoreDefault, &QPushButton::clicked, this, &Setup::restoreDefaultShortcuts);
    connect(ui->submit, &QPushButton::clicked, this, &Setup::onSubmitClicked);

    // 批量连接 QCheckBox 和 QComboBox 的信号与槽
    this->connectCheckBoxesAndComboBoxes();

    this->loadSettings(); //在程序启动时加载保存的设置

}

Setup::~Setup()
{
    delete ui;
}

void Setup::onSubmitClicked()
{
    // 获取用户输入的内容
    QString feedbackText = ui->feedbackAndSuggestions->toPlainText();

    // 显示用户输入的内容
    QMessageBox::information(this, "反馈已提交", feedbackText);
}

// 批量连接 QLineEdit 、QCheckBox 和 QComboBox 的信号与槽
void Setup::connectCheckBoxesAndComboBoxes() {

    // 初始化快捷键输入框
    QList<QLineEdit*> lineEdits = this->findChildren<QLineEdit*>();

    for (QLineEdit* lineEdit : lineEdits) {
        lineEdit->setReadOnly(true);
        lineEdit->installEventFilter(this);
    }
    // 查找所有的 QCheckBox 控件
    QList<QCheckBox*> checkBoxes = this->findChildren<QCheckBox*>();
    for (QCheckBox* checkBox : checkBoxes) {
        connect(checkBox, &QCheckBox::toggled, this, &Setup::saveSettings);
    }

    // 查找所有的 QComboBox 控件
    QList<QComboBox*> comboBoxes = this->findChildren<QComboBox*>();
    for (QComboBox* comboBox : comboBoxes) {
        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Setup::saveSettings);
    }
}

// 保存用户设置
void Setup::saveSettings()
{
    qDebug() << "保存中...";
    if (m_isLoading) return;

    QSettings settings("YourCompanyName", "YourAppName");
    settings.beginGroup("Settings");

    bool enableTimerClose = ui->regularlyCloseSoftware->isChecked();
    int hour = ui->hour->currentIndex();
    int minute = ui->minute->currentIndex();
    QString theme = ui->theme->currentText();
    bool timedShutdown = ui->timedShutdown->isChecked();
    bool autoPlay = ui->startPlayingAudio->isChecked();
    QString soundEffect = ui->soundEffect->currentText();

    settings.setValue("enableTimerClose", enableTimerClose);
    settings.setValue("hour", hour);
    settings.setValue("minute", minute);
    settings.setValue("theme", theme);
    settings.setValue("timedShutdown", timedShutdown);
    settings.setValue("autoPlay", autoPlay);
    settings.setValue("soundEffect", soundEffect);

    settings.setValue("playPauseShortcut", ui->playPauseShortcut->text());
    settings.setValue("prevSongShortcut", ui->prevSongShortcut->text());
    settings.setValue("nextSongShortcut", ui->nextSongShortcut->text());
    settings.setValue("volumeUpShortcut", ui->volumeUpShortcut->text());
    settings.setValue("volumeDownShortcut", ui->volumeDownShortcut->text());

    settings.endGroup();

    emit settingsUpdated(enableTimerClose, hour, minute, theme, timedShutdown, autoPlay, soundEffect);

    qDebug() << "保存成功";
}

// 全局函数：转换快捷键字符串为大写字母
QString convertToUpperCaseShortcut(const QString &shortcut) {
    QStringList parts = shortcut.split("+");
    for (QString &part : parts) {
        bool hasLetter = false;
        for (int i = 0; i < part.size(); ++i) {
            QChar c = part.at(i);
            if (c.isLetter()) {
                hasLetter = true;
                break;
            }
        }
        if (hasLetter) {
            part = part.toUpper();
        }
    }
    return parts.join("+");
}

// 在程序启动时加载设置
void Setup::loadSettings()
{
    m_isLoading = false; // 标志变量标识正在加载设置

    QSettings settings("YourCompanyName", "YourAppName");
    settings.beginGroup("Settings");

    // 加载定时关闭设置
    bool enableTimerClose = settings.value("enableTimerClose", false).toBool();
    int hour = settings.value("hour", 0).toInt();
    int minute = settings.value("minute", 0).toInt();
    // 加载自动关闭软件后关机
    bool timedShutdown = settings.value("timedShutdown", false).toBool();
    // 加载自动播放设置
    bool autoPlay = settings.value("autoPlay", false).toBool();
    // 加载主题设置
    QString theme = settings.value("theme", "默认主题").toString();
    // 加载音效选择
    QString soundEffect = settings.value("soundEffect", "无音效").toString();

    // 加载快捷键设置
    QString playPauseShortcut = settings.value("playPauseShortcut").toString();
    QString prevSongShortcut = settings.value("prevSongShortcut").toString();
    QString nextSongShortcut = settings.value("nextSongShortcut").toString();
    QString volumeUpShortcut = settings.value("volumeUpShortcut").toString();
    QString volumeDownShortcut = settings.value("volumeDownShortcut").toString();

    // 阻止信号触发保存
    ui->regularlyCloseSoftware->blockSignals(true);
    ui->hour->blockSignals(true);
    ui->minute->blockSignals(true);
    ui->timedShutdown->blockSignals(true);
    ui->startPlayingAudio->blockSignals(true);
    ui->theme->blockSignals(true);
    ui->soundEffect->blockSignals(true);

    ui->regularlyCloseSoftware->setChecked(enableTimerClose);
    ui->hour->setCurrentIndex(hour);
    ui->minute->setCurrentIndex(minute);
    ui->timedShutdown->setChecked(timedShutdown);
    ui->startPlayingAudio->setChecked(autoPlay);
    ui->theme->setCurrentText(theme);
    int index = ui->soundEffect->findText(soundEffect);
    if (index != -1) {
        ui->soundEffect->setCurrentIndex(index);
    } else {
        ui->soundEffect->setCurrentIndex(0); // 设置为默认选项
    }
    // 更新快捷键显示
    ui->playPauseShortcut->setText(playPauseShortcut);
    ui->prevSongShortcut->setText(prevSongShortcut);
    ui->nextSongShortcut->setText(nextSongShortcut);
    ui->volumeUpShortcut->setText(volumeUpShortcut);
    ui->volumeDownShortcut->setText(volumeDownShortcut);

    // 恢复信号
    ui->regularlyCloseSoftware->blockSignals(false);
    ui->hour->blockSignals(false);
    ui->minute->blockSignals(false);
    ui->timedShutdown->blockSignals(false);
    ui->startPlayingAudio->blockSignals(false);
    ui->theme->blockSignals(false);
    ui->soundEffect->blockSignals(false);

    settings.endGroup();

    // 调试信息
    qDebug() << "加载设置成功！";
}

// 默认快捷键配置
const QMap<QString, QString> Setup::defaultShortcuts = {
    {"playPauseShortcut", "SPACE"},
    {"prevSongShortcut", "LEFT"},
    {"nextSongShortcut", "RIGHT"},
    {"volumeUpShortcut", "UP"},
    {"volumeDownShortcut", "DOWN"}
};

// 检查快捷键冲突
void Setup::checkShortcutConflict(const QString &newShortcut, QLineEdit *currentLineEdit) {
    QList<QLineEdit*> lineEdits = {
        ui->playPauseShortcut,
        ui->prevSongShortcut,
        ui->nextSongShortcut,
        ui->volumeUpShortcut,
        ui->volumeDownShortcut
    };

    foreach (QLineEdit *lineEdit, lineEdits) {
        if (lineEdit != currentLineEdit && lineEdit->text() == newShortcut) {
            // 弹出警告
            QMessageBox::warning(this, "快捷键冲突", QStringLiteral("快捷键 %1 已被用于 %2，请重新设置！")
                                                         .arg(newShortcut)
                                                         .arg(getShortcutActionName(lineEdit)));
            // 回滚新设置的快捷键
            currentLineEdit->setText(currentLineEdit->property("previousShortcut").toString());
            break;
        }
    }
}

// 获取快捷键对应的控件名称
QString Setup::getShortcutActionName(QLineEdit *lineEdit) {
    if (lineEdit == ui->playPauseShortcut) {
        return "播放/暂停";
    } else if (lineEdit == ui->nextSongShortcut) {
        return "下一曲";
    } else if (lineEdit == ui->prevSongShortcut) {
        return "上一曲";
    } else if (lineEdit == ui->volumeUpShortcut) {
        return "音量增加";
    } else if (lineEdit == ui->volumeDownShortcut) {
        return "音量减少";
    } else {
        return "未知快捷键";
    }
}

// 恢复默认快捷键
void Setup::restoreDefaultShortcuts() {
    // 恢复默认快捷键
    ui->playPauseShortcut->setText(defaultShortcuts["playPauseShortcut"]);
    ui->prevSongShortcut->setText(defaultShortcuts["prevSongShortcut"]);
    ui->nextSongShortcut->setText(defaultShortcuts["nextSongShortcut"]);
    ui->volumeUpShortcut->setText(defaultShortcuts["volumeUpShortcut"]);
    ui->volumeDownShortcut->setText(defaultShortcuts["volumeDownShortcut"]);

    // 手动触发快捷键更新信号
    emit shortcutUpdated(
        convertToUpperCaseShortcut(ui->playPauseShortcut->text()),
        convertToUpperCaseShortcut(ui->nextSongShortcut->text()),
        convertToUpperCaseShortcut(ui->prevSongShortcut->text()),
        convertToUpperCaseShortcut(ui->volumeUpShortcut->text()),
        convertToUpperCaseShortcut(ui->volumeDownShortcut->text()));
    // 保存设置
    this->saveSettings();
}

bool Setup::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(obj);

        if (lineEdit) {
            // 判断是否只按下了修饰符键（Shift、Ctrl、Alt等）
            bool onlyModifiers = (keyEvent->key() == Qt::Key_Shift) ||
                                 (keyEvent->key() == Qt::Key_Control) ||
                                 (keyEvent->key() == Qt::Key_Alt) ||
                                 (keyEvent->key() == Qt::Key_Meta);

            if (onlyModifiers) {
                // 忽略单独的修饰符键，不更新快捷键
                return true;
            }

            // 保存之前的快捷键值
            lineEdit->setProperty("previousShortcut", lineEdit->text());

            // 获取完整的键组合代码（包含修饰符）
            int keyCombination = (keyEvent->modifiers() | keyEvent->key());
            QKeySequence keySeq(keyCombination);
            QString keySequence = keySeq.toString(QKeySequence::NativeText);

            // 转换为大写
            keySequence = convertToUpperCaseShortcut(keySequence);

            // 更新快捷键对应的 QLineEdit
            lineEdit->setText(keySequence);

            // 检查快捷键冲突
            checkShortcutConflict(keySequence, lineEdit);

            // 触发快捷键更新信号
            emit shortcutUpdated(
                convertToUpperCaseShortcut(ui->playPauseShortcut->text()),
                convertToUpperCaseShortcut(ui->nextSongShortcut->text()),
                convertToUpperCaseShortcut(ui->prevSongShortcut->text()),
                convertToUpperCaseShortcut(ui->volumeUpShortcut->text()),
                convertToUpperCaseShortcut(ui->volumeDownShortcut->text())
                );
            // 保存设置
            this->saveSettings();

            return true; // 拦截事件
        }
    }

    return QWidget::eventFilter(obj, event);
}
