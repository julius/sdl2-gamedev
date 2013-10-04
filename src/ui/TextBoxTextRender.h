#ifndef UI_TEXTBOXTEXTRENDER_H
#define UI_TEXTBOXTEXTRENDER_H

#include <vector>

#include <math/Point.h>
#include <math/Size.h>
#include <ui/BasicRender.h>
#include <ui/SDL_opengl.h>
#include <ui/ShaderProgram.h>
#include <util/Log.h>


class CharMap;
class Surface;
class TextBoxText;

/**
 * TextBoxTextRender class, for rendering TextBoxText
 *
 * @author SwarmingLogic (Roald Fernandez)
 */
class TextBoxTextRender : public BasicRender
{
public:
  TextBoxTextRender();
  virtual ~TextBoxTextRender();

  virtual void initialize() override;
  void postConfigureInitialize();
  virtual void render(float currentTime) override;
  virtual void handleResize(int width, int height) override;

  // Required initializations
  void setTextBoxText(const TextBoxText& textBoxText);
  void setCharMap(const CharMap& charmap);
  void loadImage(const std::string& filename);

  // Dynamic variables
  void setText(const std::string& text);
  Point getPosition() const;
  void setPosition(Point position);

  void setZoomFactor(unsigned char zoomFactor);

  bool isReady() const;
private:
  void prepareVertices();
  void prepareTexcoords();
  void updateQuad();
  void updateTex();

  Log log_;

  // Data objects
  std::unique_ptr<CharMap> charmap_;
  std::unique_ptr<Surface> surface_;
  std::unique_ptr<TextBoxText> textBoxText_;

  // Environment
  Size viewport_;
  Point position_;

  // Rendering specific
  ShaderProgram program_;
  GLuint vertexBuffer_;
  // GLuint textureBuffer_;
  std::vector<GLfloat> vertices_;
  // std::vector<GLfloat> texcoords_;
  unsigned char zoomFactor_;

  // Shader specific texture paramters.
  GLint paramId_Tex1_;
  GLint paramId_Viewport_;
  GLint paramId_charBoxDimensions_;
  GLint paramId_offset_;
  void updateShader();

  // NonCopyable
  TextBoxTextRender(const TextBoxTextRender& c);
  TextBoxTextRender& operator=(const TextBoxTextRender& c);
};

#endif