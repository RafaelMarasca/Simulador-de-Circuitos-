#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QWidget>
#include <QObject>
#include <QScrollBar>
#include <QPushButton>
#include "Circuit.h"
#include <QScrollArea>
#include <QMouseEvent>
#include "GraphicComponent.h"

enum sts{UNSAVED,MODIFIED,OK,ERROR};
enum type{VCC,RES,NONE};

class Diagram : public QWidget
{
    Q_OBJECT
public:
    explicit Diagram(QWidget *parent = nullptr);

    void setFileName(QString file);
    QString getFileName();
    void load();
    void save();
    enum sts getStatus();
    void setSelectedObject(enum type);

    protected:
        void mousePressEvent(QMouseEvent* event) override;
        //void mouseMoveEvent(QMouseEvent* event) override;
       // void mouseReleasedEvent(QMouseEvent* event);

signals:
    void modified(bool checked = false);
    void loadError(bool checked = false);


public slots:
    void upScale();
    void downScale();
   // void insert();
   // void remove();
   // void query();

private:
    QPushButton* zoomIn;
    QPushButton* zoomOut;
    std::string fileName;
    enum sts status;
    void initializeDiagram();

    CCT::Circuit circuit;

    void setStatus(enum sts newStatus);
    void paintEvent(QPaintEvent* event) override;
    qreal scale;
    qreal x,y;

    //std::list<std::pair<enum selected,QPoint>> drawList;
    std::list<GraphicComponent*> drawList;
    enum type selected;
};

#endif // DIAGRAM_H
