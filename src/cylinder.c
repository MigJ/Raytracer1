/*
** cylinder.c for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sat Feb 25 17:00:24 2017 Joubert Miguel
** Last update Wed Mar 15 01:19:36 2017 Joubert Miguel
*/

#include "../include/my.h"

t_attributs		get_cylinder(t_attributs att)
{
  att.color.b = 255;
  att.color.a = 255;
  att.eye_pos.x = -1000;
  att.eye_pos.y = 0;
  att.eye_pos.z = 0;
  att.dist_to_plane = 400;
  att.screen_size.x = 550;
  att.screen_size.y = 450;
  att.screen_pos.x = 0;
  att.screen_pos.y = 0;
  att.light_vector.x = 1000;
  att.light_vector.y = 1500;
  att.light_vector.z = 0;
  att.semiangle = 100;
  return (att);
}

float			intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
					   float radius)
{
  float			a;
  float			b;
  float			c;
  float			delta;
  float			x1;
  float			x2;

  a = pow(dir_vector.x, 2.0) + pow(dir_vector.y, 2.0);
  b = 2 * (dir_vector.x * eye_pos.x + dir_vector.y * eye_pos.y);
  c = pow(eye_pos.x, 2.0) + pow(eye_pos.y, 2.0) - pow(radius, 2.0);
  delta = pow(b, 2.0) - 4 * a * c;
  if (delta < 0 || (dir_vector.x == 0 && dir_vector.y == 0)) return (-1);
  else if (delta == 0 && a != 0) return (-b / (2.0 * a));
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

sfVector3f		get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f		norm;

  norm.x = intersection_point.x;
  norm.y = intersection_point.y;
  norm.z = 0.0f;
  return (norm);
}

void			radius_loop_cylinder(t_attributs att,
					     t_my_framebuffer *framebuffer)
{
  while (att.screen_pos.y != att.screen_size.y)
    {
      while (att.screen_pos.x != att.screen_size.x)
	{
	  att.dir_eye_vector =
	    calc_dir_vector(att.dist_to_plane, att.screen_size, att.screen_pos);
	  if ((att.dist_to_light =
	       intersect_cylinder(att.eye_pos, att.dir_eye_vector, att.semiangle)) > 0)
	    {
	      att.intersection_point =
		calc_dir_vector(att.dist_to_light, att.screen_size, att.screen_pos);
	      att.normal = get_normal_cylinder(att.intersection_point);
	      att.color.b *= get_light_coef(att.light_vector, att.normal);
	      my_put_pixel(framebuffer, att.screen_pos.x, att.screen_pos.y, att.color);
	    }
	  att.color.b = 255;
	  att.screen_pos.x++;
	}
      att.screen_pos.x = 0;
      att.screen_pos.y++;
    }
}

void			drawing_cylinder(sfRenderWindow *window, sfSprite *sprite,
					 t_my_framebuffer *framebuffer)
{
  sfTexture		*texture;
  t_attributs		att;

  att = get_cylinder(att);
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  radius_loop_cylinder (att, framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}
