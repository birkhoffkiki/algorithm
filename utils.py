def rename_batch(path,target_path):
    """
    path:glob args
    批量重命名文件
    """
    import skimage.io as io
    import os
    import glob
    file_type = '.'+path.split('.')[-1]
    file_name_list = glob.glob(path)
    for index,name in enumerate(file_name_list):
        name_new = target_path
        name_new = os.path.join(name_new,str(index)+file_type)
        print(name_new)
        os.rename(name,name_new)

path = "/home/kara/temp_cache/*.jpg"
rename_batch(path,'/home/kara/temp_cache')
