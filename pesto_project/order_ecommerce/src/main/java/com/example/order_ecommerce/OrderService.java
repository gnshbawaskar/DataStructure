package com.example.order_ecommerce;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;

@Service
public class OrderService {
    @Autowired
    private OrderRepository orderRepository;

    public Order placeOrder(Order order) {
        order.setOrderDate(LocalDateTime.now());
        return orderRepository.save(order);
    }

    public List<Order> getOrdersByUserId(Long userId) {
        List<Order> allOrder = new ArrayList<>();
        List<Order> userOrder = new ArrayList<>();
        allOrder = orderRepository.findAll();
        for (Order ord : allOrder) {
            if (Objects.equals(ord.getUserId(), userId))
            {
                userOrder.add(ord);
            }
        }
        return userOrder;
    }
}

