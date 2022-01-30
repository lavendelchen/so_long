//doesnt work!!!

static void	free_images(t_img *img)
{
	free(img->space);
	free(img->wall);
	free(img->coll[0]);
	free(img->coll[1]);
	free(img->coll[2]);
	free(img->coll[3]);
	free(img->exit[0]);
	free(img->exit[1]);
	free(img->blood);
	free(img->end);
}

void	free_everything(t_mlx *all) //need to test !!
{
	int	i;

	free(all->mlx_ptr);
	free(all->win_ptr);
	i = 0;
	while (all->map.map[i] != NULL)
	{
		free(all->map.map[i]);
		i++;
	}
	free(all->map.map);
	free(all->map.strmap);
	i = 0;
	while (i < all->map.exitcount)
	{
		free(all->map.exits[i]);
		i++;
	}
	free(all->map.exits);
	free_images(&all->img);
}