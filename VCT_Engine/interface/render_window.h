#pragma once
struct WindowSettings
{
    unsigned int width;
    unsigned int height;
    std::pair<int, int> position;
    std::string title;
    WindowSettings() : width(1280), height(720), title("Default") {};
    virtual ~WindowSettings() {};
};

class RenderWindow
{
    private:
        GLFWwindow * windowHandler;
        bool isOpen;
        WindowSettings settings;

        static void onErrorCallback(int code, const char * description);
    public:
        int Open();
        void Destroy();
        void SetPosition(const int x, const int y);
        void SetAsCurrentContext();
        RenderWindow();
        virtual ~RenderWindow();
        GLFWwindow * Handler() const { return windowHandler; }
        const WindowSettings& Settings() const { return settings; }
};