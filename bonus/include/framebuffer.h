/*
** framebuffer.h for  in /home/joubert/delivery/raytracer1
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Mar 14 18:34:24 2017 Joubert Miguel
** Last update Tue Mar 14 18:37:48 2017 Joubert Miguel
*/

#ifndef _FRAMEBUFFER_H_
# define _FRAMEBUFFER_H_

typedef  struct s_my_framebuffer
{
  sfUint8 *pixels;
  int width ;
  int height;
}t_my_framebuffer;

#endif /* _FRAMEBUFFER_H_ */
