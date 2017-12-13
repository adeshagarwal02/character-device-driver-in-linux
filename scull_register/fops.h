struct file_operations fops=
{
	open	: open_cdev,
	release	: release_cdev
};
