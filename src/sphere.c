/*
** sphere.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 15:44:19 2017 Joubert Miguel
** Last update Thu Mar  2 15:36:51 2017 Joubert Miguel
*/

#include <SFML/Graphics.h>
#include <math.h>

float	intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	x1;
  float	x2;

  a = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0) + pow(dir_vector.z, 2.0);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
  c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) + pow(eye_pos.z, 2.0) - pow(radius, 2.0);
  delta = pow(b, 2.0) - 4.0 * a * c;
  if (delta < 0 || (dir_vector.x == 0 && dir_vector.y == 0)) return (-1);
  else if (delta == 0) return (-b / (2.0 * a));
  else
    {
      x1 = (-b + sqrt(delta)) / (2.0 * a);
      x2 = (-b - sqrt(delta)) / (2.0 * a);
    }
  if (x1 < x2 && x1 > 0) return (x1);
  else if (x1 < 0 && x2 > 0) return (x2);
  else if (x2 < x1 && x2 > 0) return (x2);
  else if (x2 < 0 && x1 > 0) return (x1);
  else if (x2 < 0 && x1 < 0) return (-1);
  return (0);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f	norm;

  norm.x = intersection_point.x;
  norm.y = intersection_point.y;
  norm.z = intersection_point.z;
  return (norm);
}
