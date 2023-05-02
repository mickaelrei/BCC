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

dir="lista-$list_number"

mkdir $dir

for i in $(seq 1 $exercises_amount)
do
    if [ ${#i} -eq 1 ]; then
	filename="$dir/$initials-$subject-0$list_number-Ex-0$i$extension"
    else
        filename="$dir/$initials-$subject-0$list_number-Ex-$i$extension"
    fi
    touch $filename
done
