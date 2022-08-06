#include "Core/application.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <glm/vec4.hpp>
#include <imgui.h>
#include <imconfig.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <ImGuizmo.h>
#include <entt.hpp>
#include <stb_image.h>
#include <yaml-cpp/yaml.h>
#include <assimp/Importer.hpp>
#include <q3.h>

void Aalforreca::testFunction()
{
    glm::vec4 clearColor{0.0f, 0.2f, 0.2f, 1.0f};
    spdlog::info("spdlog version {}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    spdlog::info("Hello world! {0:d}", clearColor.length());

    if (!glfwInit())
        return;

    const auto glfwVersion = glfwGetVersionString();
    spdlog::info(glfwVersion);
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 5 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    GLFWwindow* window = glfwCreateWindow( 1024, 768, "Test", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent( window );
    glfwSwapInterval( 1 );
    gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress );

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO & io = ImGui::GetIO();
    (void)io;
    ImGui_ImplGlfw_InitForOpenGL( window, true );
    const char * glsl_version = "#version 450";
    ImGui_ImplOpenGL3_Init( glsl_version );
    bool   show_demo_window    = true;
    bool   show_another_window = false;
    ImVec4 clear_color         = ImVec4( 0.85f, 0.55f, 0.60f, 1.00f );

    ImGuizmo::SetOrthographic(false);

    entt::entity entity = entt::null;

    stbi_set_flip_vertically_on_load(1);

    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "Scene" << YAML::Value << "Untitled";
    out << YAML::EndMap;

    Assimp::Importer assimpImporter;

    q3Transform q3tr;

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()!
        // You can browse its code to learn more about Dear ImGui!).
        if( show_demo_window )
            ImGui::ShowDemoWindow( &show_demo_window );

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f       = 0.0f;
            static int   counter = 0;

            ImGui::Begin( "Hello, world!" ); // Create a window called "Hello, world!" and append into it.

            ImGui::Text( "This is some useful text." );          // Display some text (you can use a format strings too)
            ImGui::Checkbox( "Demo Window", &show_demo_window ); // Edit bools storing our window open/close state
            ImGui::Checkbox( "Another Window", &show_another_window );

            ImGui::SliderFloat( "float", &f, 0.0f, 1.0f );             // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3( "clear color", (float *)&clear_color ); // Edit 3 floats representing a color

            if( ImGui::Button( "Button" ) ) // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text( "counter = %d", counter );

            ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
            ImGui::End();
        }

        // 3. Show another simple window.
        if( show_another_window )
        {
            ImGui::Begin( "Another Window", &show_another_window ); // Pass a pointer to our bool variable (the window will have a closing
                                                                    // button that will clear the bool when clicked)
            ImGui::Text( "Hello from another window!" );
            if( ImGui::Button( "Close Me" ) )
                show_another_window = false;
            ImGui::End();
        }

        ImGui::Render();

        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );

        glfwSwapBuffers(window);
    }
}
