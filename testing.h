#ifndef TESTING_H
#define TESTING_H
int		main(int argc, char **argv);
void	cmd_help();
int		process_cmd(char **words);
int		process_stdin(void);
int		process_script(char *filename);
int		idx_atoi(char *index_str);
void	cmd_rf(char *filename);
void	cmd_solve(void);
void	cmd_move(int index, int x, int y);
void	cmd_inb(int i);
void	cmd_overlaps_all(void);
void	cmd_overlaps(int i, int j);
void	cmd_del(int index);
void	cmd_reset(void);
void	cmd_list();
void	cmd_set(int index, int id, int x, int y);
void	cmd_show(int i);
void	cmd_next_pos(int i);
void	print_tet_listing(int i);
void	cmd_size(int size);
void	cmd_print();
int		get_number_of_tets();

void	print_tet_raw(char *str);
void	print_shape(unsigned short shape);
void	test_identify(char *data);

#endif
