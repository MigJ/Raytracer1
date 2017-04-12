/*
** cond.h for  in /home/joubert/delivery/raytracer1/bonus
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Mar 19 19:34:45 2017 Joubert Miguel
** Last update Sun Mar 19 19:36:47 2017 Joubert Miguel
*/

#ifndef _COND_H_
# define _COND_H_

#include "my.h"

typedef struct s_cond
{
  int            i;
  int            draw;
  int            reset;
  sfVector2f     mario_pos;
  sfVector2f     sprite_pos;
}t_cond;

#endif /* _COND_H_ */
