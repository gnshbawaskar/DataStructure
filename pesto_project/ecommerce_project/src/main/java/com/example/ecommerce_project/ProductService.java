package com.example.ecommerce_project;

import com.example.ecommerce_project.Product;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.ArrayList;
import java.util.List;

@Service
public class ProductService {

    @Autowired
    private ProductRepository productRepository;
    public ProductDetails addProduct(Product product, String username) {
        ProductDetails pd = new ProductDetails();
        pd.setName(product.getName());
        pd.setQuantity(product.getQuantity());
        pd.setPrice(product.getPrice());
        pd.setUsername(product.getUsername());
        return productRepository.save(pd);
    }
    public List<ProductDetails> getAllProducts(String username) {
        List<ProductDetails> allProduct = new ArrayList<ProductDetails>();
        allProduct = productRepository.findAll();
        for (ProductDetails prod : allProduct) {
            if (prod.username.equals(username))
                allProduct.add(prod);
        }
        return allProduct;
    }
}
