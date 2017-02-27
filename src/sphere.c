/*
** sphere.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 15:44:19 2017 Joubert Miguel
** Last update Mon Feb 27 23:56:17 2017 Joubert Miguel
*/

#include <SFML/Graphics.h>
#include <math.h>

float	intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;
  float	k;

  a = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0) + pow(dir_vector.z, 2.0);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y + eye_pos.z * dir_vector.z);
  c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) + pow(eye_pos.z, 2.0) - pow(radius, 2.0);
  delta = pow(b, 2.0) - 4.0 * a * c;
  if (delta < 0 || (dir_vector.x == 0 && dir_vector.y == 0 && dir_vector.z)) return (-1);
  else if (delta == 0) return (-b / (2.0 * a));
  else k = ((-b + sqrt(delta)) / (2.0 * a) < (-b - sqrt(delta)) /(2.0 * a))
	 ? (-b + sqrt(delta)) / (2.0 * a) : (-b - sqrt(delta)) / (2.0 * a);
  if (k < 0) return (-1);
  return (k);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  float		norme;

  norme = sqrt(pow(intersection_point.x, 2.0) +
	       pow(intersection_point.y, 2.0) +pow(intersection_point.z, 2.0));
  if (norme == 0) return (intersection_point);
  intersection_point.x /= norme;
  intersection_point.y /= norme;
  intersection_point.z /= norme;
  return (intersection_point);
}
