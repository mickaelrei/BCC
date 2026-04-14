function [Q, R] = qr(A)
    n = size(A, 1);
    G = eye(n);

    for i = 1:n
        g = A(:,i);

        for j = 2:i
            prev = G(:,j-1);
            g = g - dot(g, prev) / dot(prev, prev) * prev;
        end
        G(:,i) = g;
    end

    Q = zeros(n);
    for i = 1:n
        Q(:,i) = G(:,i) / norm(G(:,i));
    end

    R = Q' * A;
end