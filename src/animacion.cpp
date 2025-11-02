#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
using namespace std;
using namespace ftxui;


int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Full(), 
        Dimension::Fixed(24)
    );


    // Agregar código de los elementos de la animación
    const vector<u32string> espacio = {
    U"                                                             .",
    U"                            .              .        .             .",
    U"  .                               .       .                 .        .",
    U"        o                             .                   .",
    U"                        .                  .           .",
    U"          0     .",
    U"                 .          .                                     ,",
    U"            \\          .                         ",
    U"             \\   ",
    U"              o                      .                   .            .",
    U"               \\                 ,             .                .",
    U"               #\\##\\#      .                                      .",
    U"             #  #O##\\###                                        .",
    U"            #*#  #\\##\\###                                            ,",
    U"            ##*#  #\\##\\##                                    ",
    U"             ##*#  #o##\\#         .                             ,       .",
    U"                *#  #\\#     .                    .                       ",
    U"                      \\          .                         ",
    U"____^/\\___^--____/\\____O______________/\\/\\---/\\___________---______________",
    U"   /\\^   ^  ^    ^                  ^^ ^  '\\ ^          ^       ---",
    U"         --           -            --  -      -         ---  __       ^",
    U"   --  __                      ___--  ^  ^                         --  __"




    };


    const vector<u32string> alien = {
    U"     ___",
    U" ___/xxx\\___",
    U"/xxx'---'xxxx\\",
    U"'--_______--'",
    U"     / \\",
    U"    /   \\",
    U"    /\\O/\\",
    U"    / | \\",
    U"    // \\\\"

   
    };

    const vector<u32string> estrellas1 = {
    U"   *        .        *     .",
    U"        .       *        .     *",
    U"  *         .        .       *     .",
    U"     .   *        .        *",
    U" *        .         *         .",
    U"       *     .        .      *",
    U"  .     *         .      *       .",
    U"     *       .         *     .",
    U" .        *     .         *",
    U"        .     *       .        *",
    U"   *         .     *        .",
    U" .     *        .       *     .",
    U"     .        *       .     *",
    U" *       .         *       .",
    U"     .     *        .     *",
    U"  *        .     *       .     *"

    };

    const vector<u32string> estrellas2 = {
    U"   *        .        *     .",
    U"        .       *        .     *",
    U"  *         .        .       *     .",
    U"     .   *        .        *",
    U" *        .         *         .",
    U"       *     .        .      *",
    U"  .     *         .      *       .",
    U"     *       .         *     .",
    U" .        *     .         *",
    U"        .     *       .        *",
    U"   *         .     *        .",
    U" .     *        .       *     .",
    U"     .        *       .     *",
    U" *       .         *       .",
    U"     .     *        .     *",
    U"  *        .     *       .     *"


    };

    const vector<u32string> satelite = {

    U"   |====|",
    U" --|xxxx|--",
    U"   |____|",
    U"    ||||",
    U"  //____\\"


                               
    };

    const vector<u32string> carrito = {

    U" ___|___________|_",
    U"| []  NASA    []  |",
    U"|______|___|______|",
    U"  (O)   (O)    (O)"

    };

    const vector<u32string> bandera = {
    U"  |\\",
    U"  | \\",
    U"  |__\\",
    U"  |    ",
    U"  |    ",
    U" / \\"

    };

    const vector<u32string> luna = {
    U"          _.._",
    U"       .' .-'`",
    U"      /  /",
    U"      |  |",
    U"      \\  \\",
    U"       '._'-._",
    U"          ```"
    
};


    GestorDibujos gestor;
    gestor.Agregar(Dibujo(0, 0, espacio, ftxui::Color::GrayLight));   // fondo
    gestor.Agregar(Dibujo(30, 12, alien, ftxui::Color::Green));
    gestor.Agregar(Dibujo(1,2, estrellas1, ftxui::Color::GrayLight));
    gestor.Agregar(Dibujo(40,2, estrellas2, ftxui::Color::GrayLight));
    gestor.Agregar(Dibujo(25,2, satelite, ftxui::Color::Red1));
    gestor.Agregar(Dibujo(10,19, carrito, ftxui::Color::BlueLight));
    gestor.Agregar(Dibujo(50,3, luna, ftxui::Color::Yellow1));
    gestor.Agregar(Dibujo(5,15, bandera, ftxui::Color::BlueLight));

   int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
    // Limpia la pantalla
        screen.Clear();


        // Animación
        gestor.dibujos[1].x = 30 + (frame % 20);


        gestor.dibujos[2].x = 1 + (frame % 2);
        gestor.dibujos[2].y = 2 + (frame % 3);

        gestor.dibujos[3].x = 40 - (frame % 2);
        gestor.dibujos[3].y = 2 + (frame % 3);

        gestor.dibujos[4].x = 25 + (frame % 7);
        gestor.dibujos[4].y = 2 + (frame % 3);

        gestor.dibujos[5].x = 10 + (frame % 20);

        gestor.dibujos[6].x = 50 - (frame % 10);
        gestor.dibujos[6].y = 3 + (frame % 3);

        gestor.DibujarTodos(screen);


        // Imprime la pantalla y resetea el cursor
        cout << screen.ToString();
        cout << screen.ResetPosition();
        cout << std::flush;



        this_thread::sleep_for(std::chrono::milliseconds(300));
}

cout << "Animación terminada. Presiona Enter para salir...\n";
cin.get();

return 0;
}
