#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H


#include <QOpenGLWidget>
#include <memory>


class CommandTransform;
class Renderer;


class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget* parent = nullptr);
    ~OpenGLWidget() override;

    QSize sizeHint() const override;
    // openGL을 렌더링하기 위한 virtual 함수. QGLWidget 위젯을 업데이트하면
    // 이 함수가 호출된다.
    void paintGL() override;

    // openGL의 viewport, project 등을 설정한다. 위젯의 크기가 변경될 때
    // 자동으로 호출된다. QGLWidget이 처음 실행될 때 resize이벤트가 자동으로 호출된다.
    void resizeGL(int w, int h) override;

    // openGL 렌더링 context를 설정한다. 위의 함수가 호출되기 전 초기화를 위해 호출된다.
    void initializeGL() override;



    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void translate(const QPoint& startPoint, const QPoint& endPoint);



private:
    QPoint prePoint;

    std::shared_ptr<CommandTransform> commandTranslate;
    std::shared_ptr<Renderer> renderer;
};

#endif // OPENGLWIDGET_H
