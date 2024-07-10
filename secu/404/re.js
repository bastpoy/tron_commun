const fs = require('fs');

const filePath = 'access.log';
let str;

// Fonction pour lire le contenu du fichier
fs.readFile(filePath, 'utf8', (err, data) => {
    if (err) {
        console.error("Une erreur s'est produite lors de la lecture du fichier :", err);
        return;
    }
    str = data.split('\n').forEach((el) =>{
        if(el.search("http://"))
        {
            console.log(el.substring(el.indexOf("http://")));
        }
    });
    // console.log(str[0]);
    // console.log(str.match(emailRegex));
})
