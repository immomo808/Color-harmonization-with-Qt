

#include "myvideosurface.h"
#include "myimage.h"
#include "template.h"
//MyVideoSurface::MyVideoSurface(QObject * parent=NULL) : QAbstractVideoSurface(parent)
//{}
extern GlobalTemplate GT;

bool MyVideoSurface::present(const QVideoFrame& frame){
    if (frame.isValid()) {
        QVideoFrame cloneFrame(frame);
        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
        img = QImage(cloneFrame.bits(),
                     cloneFrame.width(),
                     cloneFrame.height(),
                     QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));

        //do something with the image ...
        //img = &img1;
        //counter++;
        //if (counter % 100 == 0) {
            counter = 0;
            //qDebug() << "PrintImage";
            QRect rect(400, 240, 800, 480);
            img = img.copy(rect);
            img = img.mirrored(true,false);
            //qDebug() << img.width() << " " << img.height();
            QImage image = show->fit500(&img);
            show->setImage(image);
            show->computeMostFitTemplateX(10);
            GT.m_TV = show->getTV();
            GT.m_image = image;
            show->update();
        //}

        cloneFrame.unmap();
        return true;
    }
    return false;
}
