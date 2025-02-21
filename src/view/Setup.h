#ifndef SETUP_H
#define SETUP_H

#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>
#include <QEvent>

namespace Ui {
class Setup;
}

class Setup : public QWidget
{
    Q_OBJECT

public:
    explicit Setup(QWidget *parent = nullptr);
    ~Setup();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

signals:
    void shortcutUpdated(const QString &playPauseShortcut,
                         const QString &nextSongShortcut,
                         const QString &prevSongShortcut,
                         const QString &volumeUpShortcut,
                         const QString &volumeDownShortcut);
    void settingsUpdated(bool enableTimerClose,
                         int hour,
                         int minute,
                         QString theme,
                         bool timedShutdown,
                         bool autoPlay,
                         QString soundEffect);

private slots:
    void saveSettings(); // 保存用户设置
    void loadSettings(); // 在程序启动时加载设置
    void connectCheckBoxesAndComboBoxes(); // 批量连接 QCheckBox 和 QComboBox 的信号与槽
    QString getShortcutActionName(QLineEdit *lineEdit); // 获取快捷键对应的控件名称
    void checkShortcutConflict(const QString &newShortcut, QLineEdit *currentLineEdit); // 转换快捷键字符串为大写字母
    void restoreDefaultShortcuts(); // 恢复默认快捷键
    void onSubmitClicked(); // 提交反馈与建议

private: 
    Ui::Setup *ui;
    bool m_isLoading = true; // 增加一个标志变量，用于判断是否在加载设置

    // 默认快捷键配置
    static const QMap<QString, QString> defaultShortcuts; // 默认快捷键
};

#endif // SETUP_H
