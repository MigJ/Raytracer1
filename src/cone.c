/*
** cone.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 17:19:54 2017 Joubert Miguel
** Last update Mon Feb 27 16:04:30 2017 Joubert Miguel
*/

#include <SFML/Graphics.h>
#include <math.h>

float	intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float semiangle)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	k;

  a = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0) - pow(dir_vector.z, 2.0);
  b = 2 * (eye_pos.x * dir_vector.x) + 2 * (eye_pos.y * dir_vector.y) - 2 * (eye_pos.z * dir_vector.z);
  c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) - pow(eye_pos.z, 2.0);
  delta = pow(b, 2.0) - 4 * a * c;
  if (delta < 0) return (-1);
  else if (delta == 0) return (-b / (2.0 * a));
  else k = ((-b + sqrt(delta)) / (2.0 * a) < (-b - sqrt(delta)) /(2.0 * a))
	 ? (-b + sqrt(delta)) / (2.0 * a) : (-b - sqrt(delta)) / (2.0 * a);
  return (k);
}
