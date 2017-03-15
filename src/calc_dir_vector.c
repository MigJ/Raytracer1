/*
** calc_dir_vector.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 15:36:54 2017 Joubert Miguel
** Last update Tue Mar 14 18:31:28 2017 Joubert Miguel
*/

#include "../include/my.h"

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = screen_size.x / 2 - screen_pos.x;
  dir_vector.z = screen_size.y / 2 - screen_pos.y;
  return (dir_vector);
}
