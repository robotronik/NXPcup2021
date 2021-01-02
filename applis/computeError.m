function [all_errors] = computeError(Y, all_filts, all_images)
%COMPUTEERROR Compute all the error of the image for the differents filter

[nb_filts, tmp] = size(all_filts);

[m n p] = size(Y);
% m,n = dimension de l'image
% p composante RGB

all_errors=zeros(m, n, nb_filts);

lambda = [0.2126 0.7152 0.0722]; % Importance de chaque composante RGB cf wikipedia
%lambda = [0 1 0];

for i=1:nb_filts
    % On récupère le noyau du filtre i
    current_filt=cell2mat(all_filts(i));

    for j=1:p
        % Convolution entre l'image et le filtre pour chaque composante RGB
        conv_tmp = conv2(all_images(:, :, j, i), current_filt, 'same');
        
        name = sprintf('matlab_blurred_%d.ppm', i-1)
        imwrite(uint8(conv_tmp), name)

        
        all_errors(:, :, i) = double(all_errors(:, :, i)) + double(lambda(j) *(Y(:, :, j) - uint8(conv_tmp))) ;
    end

end

end
