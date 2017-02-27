/*
** translate.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Mon Feb 27 16:36:42 2017 Joubert Miguel
** Last update Mon Feb 27 16:41:42 2017 Joubert Miguel
*/

#include <SFML/Graphics.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
