in vec4 vertex;
//out vec4 vertexColor;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 transformMatrix;


void main(void)
{
    //gl_Position = mvpMatrix * vertex;
    gl_Position = projectionMatrix * viewMatrix * transformMatrix * vertex;
    //vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
}
