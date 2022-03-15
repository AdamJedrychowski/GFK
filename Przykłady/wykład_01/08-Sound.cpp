#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "GFK",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 sf::SoundBuffer music_buffer,effect_buffer;
 sf::Sound music_sound,effect_sound;

 window.setVerticalSyncEnabled(true);

 music_buffer.loadFromFile("music.ogg");
 effect_buffer.loadFromFile("effect.ogg");
 music_sound.setBuffer(music_buffer);
 effect_sound.setBuffer(effect_buffer);

 music_sound.play();
 while (window.isOpen())
  {
   while (window.pollEvent(event))
   {
    if (event.type == sf::Event::Closed) window.close();
    if (event.key.code == sf::Keyboard::G)
    {
     music_sound.setVolume(50.0f);
     effect_sound.play();
    }
   }
   
   window.clear(sf::Color::Black);
   if (effect_sound.getStatus() == sf::Sound::Stopped && music_sound.getVolume() == 50.0f) music_sound.setVolume(100.0f);
   window.display();
  }
 return 0;
}