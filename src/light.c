/*
** light.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Feb 28 00:13:02 2017 Joubert Miguel
** Last update Tue Mar 14 18:32:34 2017 Joubert Miguel
*/

#include "../include/my.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	norme;
  float	norme2;
  float	coef;

  norme = sqrt(pow(light_vector.x, 2.0) +
	       pow(light_vector.y, 2.0) + pow(light_vector.z, 2.0));
  light_vector.x = (norme != 0) ? light_vector.x / norme : light_vector.x;
  light_vector.y = (norme != 0) ? light_vector.y / norme : light_vector.y;
  light_vector.z = (norme != 0) ? light_vector.z / norme : light_vector.z;
  norme2 = sqrt(pow(normal_vector.x, 2.0) +
		pow(normal_vector.y, 2.0) + pow(normal_vector.z, 2.0));
  normal_vector.x = (norme2 != 0) ? normal_vector.x / norme2 : normal_vector.x;
  normal_vector.y = (norme2 != 0) ? normal_vector.y / norme2 : normal_vector.y;
  normal_vector.z = (norme2 != 0) ? normal_vector.z / norme2 : normal_vector.z;
  coef = normal_vector.x * light_vector.x
    + normal_vector.y * light_vector.y + normal_vector.z * light_vector.z;
  if (coef < 0) return (0);
  return (coef);
}
