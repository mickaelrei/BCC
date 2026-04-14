function [L, U, P] = plu(A)
    n = size(A, 1);

    L = eye(n);
    P = eye(n);
    U = A;

    for i = 1:n-1
        % escolher pivô (maior valor na coluna)
        [~, pivot] = max(abs(U(i:n, i)));
        pivot = pivot + i - 1;

        if abs(U(pivot, i)) < 1e-12
            error(sprintf("Cannot decompose: near-zero pivot at column %d", i))
        end

        if pivot != i
            % trocar linhas de U e P
            U([i pivot], :) = U([pivot i], :);
            P([i pivot], :) = P([pivot i], :);

            % trocar somente as colunas de L ja calculadas (até i - 1)
            L([i pivot], 1:i-1) = L([pivot i], 1:i-1);
        end

        % eliminação de gauss nas linhas da coluna
        for j = i+1:n
            m = U(j, i) / U(i, i);
            U(j, :) = U(j, :) - m * U(i, :);
            L(j, i) = m;
        end
    end
end