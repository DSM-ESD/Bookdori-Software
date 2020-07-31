#ifndef BOOKEYES_H
#define BOOKEYES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class BookEyes; }
QT_END_NAMESPACE

class BookEyes : public QWidget
{
    Q_OBJECT

public:
    BookEyes(QWidget *parent = nullptr);
    ~BookEyes();

private:
    Ui::BookEyes *ui;
};
#endif // BOOKEYES_H
