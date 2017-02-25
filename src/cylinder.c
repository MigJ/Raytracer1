/*
** cylinder.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 17:00:24 2017 Joubert Miguel
** Last update Sat Feb 25 17:09:44 2017 Joubert Miguel
*/

#include <SFML/Graphics.h>
#include <math.h>

float	intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	k;

  a = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0);
  b = 2 * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y);
  c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) - pow(radius, 2.0);
  delta = pow(b, 2.0) - 4 * a * c;
  if (delta < 0) return (-1);
  else if (delta == 0) return (-b / (2.0 * a));
  else k = ((-b + sqrt(delta)) / (2.0 * a) < (-b - sqrt(delta)) /(2.0 * a))
	 ? (-b + sqrt(delta)) / (2.0 * a) : (-b - sqrt(delta)) / (2.0 * a);
  return (k);
}
