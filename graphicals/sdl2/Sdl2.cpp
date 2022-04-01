/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** Sdl2
*/

#include "sdl2/Sdl2.hpp"

std::unique_ptr<arcade::api::Sdl2> arcade::api::Sdl2::_instance;

arcade::api::Sdl2::Sdl2() : AbstractDisplayModule("Sdl2")
{
    this->_renderer = nullptr;
    this->_window = nullptr;
    this->_keyMap = {
        {SDLK_LCTRL,        KeyCode::LControl},
        {SDLK_LSHIFT,       KeyCode::LShift},
        {SDLK_LALT,         KeyCode::LAlt},
        {SDLK_RCTRL,        KeyCode::RControl},
        {SDLK_RSHIFT,       KeyCode::RShift},
        {SDLK_RALT,         KeyCode::RAlt},
        {SDLK_MENU,         KeyCode::Menu},
        {SDLK_LEFTBRACKET,  KeyCode::LBracket},
        {SDLK_RIGHTBRACKET, KeyCode::RBracket},
        {SDLK_SEMICOLON,    KeyCode::Semicolon},
        {SDLK_COMMA,        KeyCode::Comma},
        {SDLK_PERIOD,       KeyCode::Period},
        {SDLK_QUOTE,        KeyCode::Quote},
        {SDLK_SLASH,        KeyCode::Slash},
        {SDLK_BACKSLASH,    KeyCode::Backslash},
        {SDLK_EQUALS,       KeyCode::Equal},
        {SDLK_MINUS,        KeyCode::Hyphen},
        {SDLK_SPACE,        KeyCode::Space},
        {SDLK_RETURN,       KeyCode::Enter},
        {SDLK_BACKSPACE,    KeyCode::Backspace},
        {SDLK_TAB,          KeyCode::Tab},
        {SDLK_PAGEUP,       KeyCode::PageUp},
        {SDLK_PAGEDOWN,     KeyCode::PageDown},
        {SDLK_END,          KeyCode::End},
        {SDLK_HOME,         KeyCode::Home},
        {SDLK_INSERT,       KeyCode::Insert},
        {SDLK_DELETE,       KeyCode::Delete},
        {SDLK_PLUS,         KeyCode::Add},
        {SDLK_KP_MINUS,     KeyCode::Subtract},
        {SDLK_KP_MULTIPLY,  KeyCode::Multiply},
        {SDLK_KP_DIVIDE,    KeyCode::Divide},
        {SDLK_KP_0,         KeyCode::Numpad0},
        {SDLK_a,            KeyCode::A},
        {SDLK_b,            KeyCode::B},
        {SDLK_c,            KeyCode::C},
        {SDLK_d,            KeyCode::D},
        {SDLK_e,            KeyCode::E},
        {SDLK_f,            KeyCode::F},
        {SDLK_g,            KeyCode::G},
        {SDLK_h,            KeyCode::H},
        {SDLK_i,            KeyCode::I},
        {SDLK_j,            KeyCode::J},
        {SDLK_k,            KeyCode::K},
        {SDLK_l,            KeyCode::L},
        {SDLK_n,            KeyCode::N},
        {SDLK_o,            KeyCode::O},
        {SDLK_p,            KeyCode::P},
        {SDLK_q,            KeyCode::Q},
        {SDLK_s,            KeyCode::S},
        {SDLK_t,            KeyCode::T},
        {SDLK_u,            KeyCode::U},
        {SDLK_v,            KeyCode::V},
        {SDLK_w,            KeyCode::W},
        {SDLK_x,            KeyCode::X},
        {SDLK_y,            KeyCode::Y},
        {SDLK_z,            KeyCode::Z},
    };
}

void arcade::api::Sdl2::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s",
                     SDL_GetError());
        exit(84);
    }
    createWindow({800, 600}, "Arcade | Sdl2");
    _isOpen = true;
}

void arcade::api::Sdl2::destroy()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    close();
}

void arcade::api::Sdl2::close()
{
    if (isOpen())
        SDL_Quit();
    this->_isOpen = false;
}

void arcade::api::Sdl2::clear(const arcade::api::renderer::Color &color)
{
    SDL_SetRenderDrawColor(_renderer, color.getRed(), color.getGreen(),
                           color.getBlue(), color.getAlpha());
    SDL_RenderClear(_renderer);
}

void arcade::api::Sdl2::draw(const arcade::api::renderer::IDrawable &drawable)
{
}

void arcade::api::Sdl2::createWindow(Vector2u size, const std::string &title)
{
    if (SDL_CreateWindowAndRenderer((int) size.x, (int) size.y,
                                    SDL_WINDOW_SHOWN, &_window, &_renderer) <
        0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s",
                     SDL_GetError());
        SDL_Quit();
    }
    setTitle(title);
}

bool arcade::api::Sdl2::isOpen() const
{
    return this->_isOpen;
}

bool arcade::api::Sdl2::pollEvent(std::unique_ptr<ArcadeEvent> &event)
{
    bool ev = false;
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            event = std::make_unique<event::CloseEvent>();
            return true;
        }
        if (e.key.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    ev = true;
                    event = std::make_unique<CloseEvent>();
                    break;
                case SDLK_UP:
                    ev = true;
                    event = std::make_unique<SwitchEvent>(
                        SwitchEvent::GAME, SwitchEvent::NEXT);
                    break;
                case SDLK_DOWN:
                    ev = true;
                    event = std::make_unique<SwitchEvent>(
                        SwitchEvent::GAME, SwitchEvent::PREV);
                    break;
                case SDLK_RIGHT:
                    ev = true;
                    event = std::make_unique<SwitchEvent>(
                        SwitchEvent::DISPLAY, SwitchEvent::NEXT);
                    break;
                case SDLK_LEFT:
                    ev = true;
                    event = std::make_unique<SwitchEvent>(
                        SwitchEvent::DISPLAY, SwitchEvent::PREV);
                    break;
                case SDLK_m:
                    ev = true;
                    event = std::make_unique<LaunchMenuEvent>();
                    break;
                case SDLK_r:
                    ev = true;
                    event = std::make_unique<RestartEvent>();
                    break;
                default:
                    ev = true;
                    event = std::make_unique<KeyEvent>(
                        _keyMap[e.key.keysym.sym], KeyAction::PRESSED);
            }
        }
    }
    return ev;
}

void arcade::api::Sdl2::setSize(Vector2u size)
{
    this->_size = size;
    SDL_SetWindowSize(this->_window, (int) size.x, (int) size.y);
}

void arcade::api::Sdl2::setTitle(const std::string &title)
{
    SDL_SetWindowTitle(_window, title.c_str());
    this->_title = title;
}

void arcade::api::Sdl2::setIcon(const std::string &path)
{
    SDL_Surface *Icon = SDL_LoadBMP(path.c_str());
    SDL_SetWindowIcon(_window, Icon);
    SDL_FreeSurface(Icon);
}

void arcade::api::Sdl2::setFramerateLimit(uint limit)
{
    this->_framerateLimit = limit;
}

void arcade::api::Sdl2::display()
{
    SDL_RenderPresent(_renderer);
}

extern "C" arcade::api::Sdl2 *entryPoint()
{
    return arcade::api::Sdl2::getInstance();
}

arcade::api::Sdl2 *arcade::api::Sdl2::getInstance()
{
    if (_instance == nullptr)
        _instance = std::make_unique<Sdl2>();
    return _instance.get();
}

void arcade::api::Sdl2::reset()
{
}
