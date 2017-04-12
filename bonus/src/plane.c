/*
** plane.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 16:53:59 2017 Joubert Miguel
** Last update Tue Mar 14 18:33:12 2017 Joubert Miguel
*/

#include "../include/my.h"

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  if (dir_vector.z == 0) return (-1);
  return (- (eye_pos.z / dir_vector.z));
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	norm;

  norm.x = norm.y = 0.0f;
  if (upward == 0)
    norm.z = -1.0f;
  else
    norm.z = 1.0f;
  return (norm);
}
