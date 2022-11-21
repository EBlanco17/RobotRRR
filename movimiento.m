function m=movimiento(grados)
    clc;
    fprintf('inicio\n\n');
    delete(instrfind(('Port'),('COM5')));
    s=serial('COM5','BaudRate',9600,'Terminator','CR/LF');
    fopen(s);
    pause(1);
    fprintf('puerto abierto\n\n');
    
    grado_1 = num2str(grados(1));
    grado_2 = num2str(grados(2));
    grado_3 = num2str(grados(3));
    grado_4 = num2str(grados(4));
    t = ',';
    envio =sprintf('%s%s%s%s%s%s%s',grado_1,t,grado_2,t,grado_3,t,grado_4);
    fprintf('%s\n\n', envio);
    fprintf(s, '%s',envio);
    fprintf('enviado\n\n');
    retorno =fscanf(s, '%s');
    fprintf('recibido\n\n');
    fprintf('%s\n\n',retorno);
    
    fclose(s);
    delete(s);

end