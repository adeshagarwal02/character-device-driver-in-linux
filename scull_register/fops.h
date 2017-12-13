struct file_operations fops=
{
	open	: open_cdev,
	write	: write_cdev,
	read	: read_cdev,
	release	: release_cdev
};
