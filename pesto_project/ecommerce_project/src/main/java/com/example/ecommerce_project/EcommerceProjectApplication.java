package com.example.ecommerce_project;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;
import java.util.List;

@SpringBootApplication
@RestController
@RequestMapping("/products")
public class EcommerceProjectApplication {
    @Autowired
    private ProductService productService;

    public static void main(String[] args) {
        SpringApplication.run(EcommerceProjectApplication.class, args);
    }
    @GetMapping("/hello")
    public ResponseEntity<String> hello(@RequestHeader("Auth-Token") String AuthToken) {
        return ResponseEntity.ok("Hello, world!");
    }

    @PostMapping(path = "/addproduct", consumes = "application/json", produces = "application/json")
    public ResponseEntity<String> addProduct(@RequestHeader("Auth-Token") String AuthToken,@RequestBody Product product) {
        RestTemplate restTemplate = new RestTemplate();
        String url = "http://localhost:8082/users/authorize";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.set("Auth-Token", AuthToken);
        // Wrap the headers and body into an HttpEntity
        HttpEntity<String> requestEntity = new HttpEntity<>("{}", headers);
        ResponseEntity<AuthResponse> response = restTemplate.exchange(
                url,
                HttpMethod.GET,
                requestEntity,
                AuthResponse.class
        );
        if (200 == response.getStatusCodeValue())
        {
            AuthResponse res = response.getBody();
            if (res.status.equals("SUCCESS")) {
                productService.addProduct(product,res.userName);
            }

            return ResponseEntity.ok("Product added successfully");
        }
        return ResponseEntity.ok("You are not authorize to add product");
    }

    @GetMapping("/getall")
    public ResponseEntity<List<ProductDetails>> getAllProducts(@RequestHeader("Auth-Token") String AuthToken) {
        RestTemplate restTemplate = new RestTemplate();
        String url = "http://localhost:8082/users/authorize";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.set("Auth-Token", AuthToken);
        // Wrap the headers and body into an HttpEntity
        HttpEntity<String> requestEntity = new HttpEntity<>("{}", headers);
        ResponseEntity<AuthResponse> response = restTemplate.exchange(
                url,
                HttpMethod.GET,
                requestEntity,
                AuthResponse.class
        );

        // Print the response status code and body
        List<ProductDetails> productList = new ArrayList<>();
        if (200 == response.getStatusCodeValue())
        {
            AuthResponse res = response.getBody();
            if (res.status.equals("SUCCESS")) {
                productList = productService.getAllProducts(res.userName);
            }
        }
        return ResponseEntity.ok(productList);
    }
}
