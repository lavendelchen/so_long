//doesnt work!!!

static void	free_images(t_img *images)
{
	free(images->space);
	free(images->wall);
	free(images->coll[0]);
	free(images->coll[1]);
	free(images->coll[2]);
	free(images->coll[3]);
	free(images->exit[0]);
	free(images->exit[1]);
	free(images->blood);
	free(images->end);
}

void	free_everything(t_mlx *all) //need to test !!
{
	int	i;

	free(all->mlx_ptr);
	free(all->win_ptr);
	i = 0;
	while (all->mapinfo.map[i] != NULL)
	{
		free(all->mapinfo.map[i]);
		i++;
	}
	free(all->mapinfo.map);
	free(all->mapinfo.strmap);
	i = 0;
	while (i < all->mapinfo.exitcount)
	{
		free(all->mapinfo.exits[i]);
		i++;
	}
	free(all->mapinfo.exits);
	free_images(&all->images);
}