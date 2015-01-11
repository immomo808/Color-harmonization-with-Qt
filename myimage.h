#ifndef MYIMAGE
#define MYIMAGE

#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QImage>
#include "template.h"
#include <QAbstractVideoSurface>
#include <QVideoFrame>
#include <QCamera>
#include <QVideoWidget>
#include "myvideosurface.h"
//![0]

class MyImage : public QQuickPaintedItem
{
//![0]
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    //Q_PROPERTY(TemplateValue TV READ TV WRITE setTV)
//![1]
public:
//![1]

    MyImage(QQuickItem *parent = 0);

    QString name() const;
    void setName(const QString &name);
    QString fileName() const;
    void setFileName(const QString &fileName);
    QImage image() const;
    void setImage(const QImage &image);
    void reset() {
        m_TV.id = -1;
    }
    void paint(QPainter *painter);
    Q_INVOKABLE void shiftImage();
    Q_INVOKABLE void shiftImageWithSpatialLocality();
    int targetHueWithSpatialLocality(int i, int j, QImage &o_image);
    Q_INVOKABLE QVariant TV() const;
    Q_INVOKABLE void setTV(const QVariant &TV);
    Q_INVOKABLE void reload();
    Q_INVOKABLE void openCamera();
    Q_INVOKABLE void setSurface();
//![2]
    Q_INVOKABLE void changeFileName(QString fileName);
    QImage fit500(QImage * image);
    void computeMostFitTemplateX(int X);
    QImage fitX(QImage * image, int X);
signals:
    void fileNameChanged();
//![2]

private:
    QByteArray device;
    MyVideoSurface surface;

    QString m_name;
    QString m_fileName;
    QImage m_image;
    TemplateValue m_TV;
//![3]
};
//![3]




#endif // MYIMAGE

