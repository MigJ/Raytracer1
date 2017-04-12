/*
** positions.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Wed Mar 15 00:18:30 2017 Joubert Miguel
** Last update Fri Mar 17 18:37:12 2017 Joubert Miguel
*/

#ifndef _ATTRIBUTS_H_
# define _ATTRIBUTS_H_

typedef struct	s_attributs
{
  sfVector2i    screen_size;
  sfVector2i    screen_pos;
  sfVector3f    eye_pos;
  sfVector3f    light_vector;
  sfVector3f    intersection_point;
  sfVector3f	normal;
  sfVector3f	dir_eye_vector;
  sfColor       color;
  float		dist_to_plane;
  float		dist_to_light;
  float		semiangle;
  float		limit_top;
  float		limit_bottom;
}t_attributs;

#endif /* _ATTRIBUTS_H_ */
