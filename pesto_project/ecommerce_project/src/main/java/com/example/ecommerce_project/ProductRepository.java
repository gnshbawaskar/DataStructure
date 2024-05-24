package com.example.ecommerce_project;

import com.example.ecommerce_project.Product;
import org.springframework.data.jpa.repository.JpaRepository;

public interface ProductRepository extends JpaRepository<ProductDetails, Long> {
}

