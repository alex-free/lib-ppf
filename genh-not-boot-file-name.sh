#!/bin/bash

cd "$(dirname "$0")"/ppf-patches
rm -rf ../ppf-c
mkdir ../ppf-c
rm -f ../template-code.txt 
rm -f ../patches.h
for f in *.PPF; do
    #generate headers and includes
    xxd -i "$f" ../ppf-c/"$f".h
    sed -i -e 's|unsigned char|const unsigned char|g' ../ppf-c/"$f".h
    echo "#include \""ppf-c/"$f".h""\" >> ../patches.h
    base=$(basename -s .PPF "$f")

    header=$(echo "$base")
    echo -e "\tapply_ppf("$header"_PPF, "$header"_PPF_len, bin);\n" >> ../template-code.txt

    count=$((count+1))
done

echo "Generated $count headers"