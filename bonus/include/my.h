/*
** my.h for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 14 18:27:07 2017 Joubert Miguel
** Last update Mon Mar 20 01:50:44 2017 Joubert Miguel
*/

#ifndef _MY_H_
# define _MY_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include <stdlib.h>
#include "framebuffer.h"
#include "attributs.h"
#include "delta.h"
#include "cond.h"

#define SCREEN_WIDTH 850
#define SCREEN_HEIGHT 650

/* PIXEL */

t_my_framebuffer        *create_pixel_buffer();

void    my_put_pixel(t_my_framebuffer *framebuffer, int x,
		     int y, sfColor color);

/* WINDOW */

void    clear_all_pixels(t_my_framebuffer *framebuffer);

int             open_window(sfRenderWindow* window, sfSprite *sprite,
			    t_my_framebuffer *framebuffer, int what);

void            skip_all_pixels(t_my_framebuffer *framebuffer, sfTexture *texture);

/*
** GAME
*/

int		       hardgame(sfRenderWindow *window, sfSprite *sprite,
				t_my_framebuffer *framebuffer, int jump);

/*
** LOOSE
*/

int             loose_menu(t_my_framebuffer *framebuffer);

/*
** DIR VECTOR
*/

sfVector3f      calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos);

/* CONE */

float   intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
		       float semiangle);

sfVector3f      get_normal_cone(sfVector3f intersection_point, float semiangle);

void            drawing_cone(sfRenderWindow *window, sfSprite *sprite,
			     t_my_framebuffer *framebuffer);

void            radius_loop_cone(t_attributs att,
				 t_my_framebuffer *framebuffer);

t_attributs             get_cone(t_attributs att);

/* CYLINDER */

float   intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
			   float radius);

sfVector3f      get_normal_cylinder(sfVector3f intersection_point);

t_attributs             get_cylinder(t_attributs att);

void            radius_loop_cylinder(t_attributs att,
				     t_my_framebuffer *framebuffer);

void            drawing_cylinder(sfRenderWindow *window, sfSprite *sprite,
				 t_my_framebuffer *framebuffer);

/* LIGHT */

float   get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);

/* PLANE */

float   intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);

sfVector3f      get_normal_plane(int upward);

/* SPHERE */

float   intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
			 float radius);

sfVector3f      get_normal_sphere(sfVector3f intersection_point);

void            drawing_sphere(sfRenderWindow *window, sfSprite *sprite,
			       t_my_framebuffer *framebuffer);

t_attributs             get_sphere(t_attributs att);

void            radius_loop_sphere(t_attributs att,
				   t_my_framebuffer *framebuffer);

/* 
** TRANSLATION
*/

sfVector3f      translate(sfVector3f to_translate, sfVector3f translations);

/*
** LOAD
*/

int        load();

int             choose_text(char *str, sfVector2f positions, sfText **object, sfFont **font);

#endif /* _MY_H_ */
