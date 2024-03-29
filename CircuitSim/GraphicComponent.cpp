/********************************************************************************************
 * @file GraphicComponent.cpp
 * @authors: Lucas Carvalho; Rafael Marasca Martins
 * @date: 30 04 2021
 * @brief Implementação da classe GraphicComponent para a inserção gráfica de componentes.
 * 
 * Este arquivo contém as implementações dos métodos e membros que são utilizados para 
 * inserir componenetes graficamente em objeto da classe Diagrama através dos métodos da 
 * classe Diagram.
 *  
 ********************************************************************************************/

#include "GraphicComponent.h"

#include <QtDebug>
#include <QPen>
#include <QPoint>
#include <QPixmap>
#include <QBitmap>

GraphicComponent::GraphicComponent(int x_ins, int y_ins,unsigned int vtx1,
                                   unsigned int vtx2, enum orien s,QObject* parent) : QObject(parent)
{
    x = x_ins;
    y = y_ins;

    //Construção das áreas de clique possíveis no componente
    if(s == VERTICAL){
        vertexArea2 = QRect(x, y, WIDTH, HEIGHT/2);
        vertexArea1 = QRect(x, y + HEIGHT/2, WIDTH, HEIGHT/2);
        boundRect = QRect(x,y,WIDTH, HEIGHT);
    }else{
        vertexArea1 = QRect(x, y, HEIGHT/2,WIDTH);
        vertexArea2 = QRect(x+HEIGHT/2, y, HEIGHT, WIDTH);
        boundRect = QRect(x,y,HEIGHT,WIDTH);
    }
    vertex1 = vtx1;
    vertex2 = vtx2;
    orientation = s;
}

int GraphicComponent::clickedArea(int x_check, int y_check){

    //Verifica qual área do componente foi clicada
    if(vertexArea1.contains(x_check,y_check)){
        return vertex1;
    }else if(vertexArea2.contains(x_check,y_check)){
        return vertex2;
    }
    return -1;
}

void GraphicComponent::draw(QPainter* painter,QColor color){

    //Verifica se alguma cor foi específicada
    if(color.isValid()){
        //Caso tenha sido, desenha o componente na cor específicada.
        QPixmap mapColored(map);
        mapColored.fill(color);
        mapColored.setMask(map.createMaskFromColor(Qt::transparent));
        painter->drawPixmap(boundRect,mapColored);
    }else{
        //Caso contrário, desenha o componente na cor padrão.
        painter->drawPixmap(boundRect,map);
    }
}

int GraphicComponent::getHeight(){return boundRect.height();}
int GraphicComponent::getWidth(){return boundRect.width();}

QPoint GraphicComponent::getTop(){
    QPoint p = boundRect.topLeft();
    int x = p.x();
    p.setX(x+(boundRect.width()/2));

    return p;
}

QPoint GraphicComponent::getBottom(){

    QPoint p = boundRect.bottomLeft();
    int x = p.x();
    p.setX(x+(boundRect.width()/2));

    return p;
}

QPoint GraphicComponent::getRight(){

    QPoint p = boundRect.topRight();

    int y = p.y();
    p.setY(y+(boundRect.height()/2));

    return p;
}

QPoint GraphicComponent::getLeft(){

    QPoint p = boundRect.topLeft();
    int y = p.y();

    p.setY(y+(boundRect.height()/2));

    return p;
}

enum orien GraphicComponent::getOrientation(){return orientation;}

Resistor::Resistor(int x, int y,unsigned int vtx1, unsigned int vtx2, enum orien s,QObject *parent):GraphicComponent(x,y,vtx1,vtx2,s,parent){

    //Possíveis modos de se desenhar o resitor.
    if(s == VERTICAL){
        map = QPixmap(":/components/resourceFile/componentFile/resistor90.png");
    }else {
        map = QPixmap(":/components/resourceFile/componentFile/resistor180.png");
    }

    componentType = CMP::RESISTOR;
    label = "R"+QString::number(vtx1);
    value = 1000;
}

Vcc::Vcc(int x, int y,  unsigned int vtx1, unsigned int vtx2, enum orien s,QObject *parent):GraphicComponent(x,y,vtx1,vtx2,s,parent){

    //Possíveis modos de se desenhar a fonte.
    if(s == VERTICAL){
        map = QPixmap(":/components/resourceFile/componentFile/vcc90.png");
    }else {
        map = QPixmap(":/components/resourceFile/componentFile/vcc180.png");
    }
    componentType = CMP::VCC;
    label = "V"+QString::number(vtx1);
    value = 12;
}


unsigned int GraphicComponent::getVertex1(){
    return vertex1;
}

unsigned int GraphicComponent::getVertex2(){
    return vertex2;
}

std::string GraphicComponent::getLabel(){
    return label.toStdString();
}

void GraphicComponent::setVertex1(unsigned int vtx){
    vertex1 = vtx;
}
void GraphicComponent::setVertex2(unsigned int vtx){
    vertex2 = vtx;
}

QRect GraphicComponent::getBoundRect(){
    return boundRect;
}
CMP::type Resistor::getType(){
    return componentType;
}
CMP::type Vcc::getType(){
    return componentType;
}

void GraphicComponent::setValue(double newValue){
    value = newValue;
}

double GraphicComponent::getValue(){
    return value;
}

QPoint GraphicComponent::getVertex1Point(){
    QPoint p;

    if(getOrientation()==VERTICAL){
        p = getBottom();
    }else{
        p = getLeft();
    }
    return p;
}

QPoint GraphicComponent::getVertex2Point(){
    QPoint p;

    if(getOrientation()==VERTICAL){
        p = getTop();
    }else{
        p = getRight();
    }
    return p;
}

void GraphicComponent::updateName(){
    label = label[0]+QString::number(vertex1);
}
