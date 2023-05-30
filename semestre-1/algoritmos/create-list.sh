if [ ! $# -eq 2 ] && [ ! $# -eq 3 ]; then
    echo "invalid amount of arguments"
    exit
fi

initials="MR"
subject="Alg"
list_number=$1
exercises_amount=$2
extension=".py"
if [ ! -z $3 ]; then
    extension=$3
fi

# Atualiza número da lista
if [ ${#list_number} -eq 1 ]; then
    list_number="0$list_number"
fi

dir="$initials-$subject-$list_number"

# Cria pasta se não existe
if [ ! -d $dir ]; then
    mkdir $dir
fi

# Cria subpasta se não existe
if [ ! -d "$dir/$extension" ]; then
    mkdir "$dir/$extension"
fi

dir="$dir/$extension"

# Cria arquivos
for i in $(seq 1 $exercises_amount)
do
    if [ ${#i} -eq 1 ]; then
	filename="$dir/$initials-$subject-$list_number-Ex-0$i$extension"
    else
        filename="$dir/$initials-$subject-$list_number-Ex-$i$extension"
    fi

    # Cria o arquivo
    touch $filename

    # Escrever o básico no arquivo, dependendo da extensão (se ele estiver vazio)
    if [ "$extension" = ".c" ] && [ ! -s $filename ]; then
        echo -ne "/**/\n\n#include <stdio.h>\n\nvoid main() {\n\n}" >> $filename
    elif [ "$extension" = ".py" ] && [ ! -s $filename ]; then
        echo -ne "''''''\n\ndef main():\n\t...\n\nif __name__ == \"__main__\":\n\tmain()" >> $filename
    fi
done

# Add gitignore for .c (se não existir)
if [ "$extension" = ".c" ]; then
    echo -ne "*\n!*.c\n!.gitignore" > "$dir/.gitignore"
fi