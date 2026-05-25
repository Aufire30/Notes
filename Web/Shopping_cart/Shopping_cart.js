/**
 * 增加购物车商品数量
 * @param {HTMLElement} btn - 点击的"+"按钮元素
 */
function add(btn)
{
    // 获取当前行的数量输入框
    var input = btn.parentElement.querySelector('.quantity');
    // 获取当前数量并加1
    var num = parseInt(input.value) || 0;
    num++;
    input.value = num;

    // 更新该商品的小计
    updateSubtotal(input);
}

/**
 * 减少购物车商品数量
 * @param {HTMLElement} btn - 点击的"-"按钮元素
 */
function sub(btn)
{
    // 获取当前行的数量输入框
    var input = btn.parentElement.querySelector('.quantity');
    var num = parseInt(input.value) || 0;
    // 如果数量小于等于1，则不允许再减少
    if(num <= 1)
    {
        return;
    }
    num--;
    input.value = num;

    // 更新该商品的小计
    updateSubtotal(input);
}

/**
 * 更新小计的函数：根据数量重新计算并更新商品小计
 * @param {HTMLElement} quantityInput - 数量输入框元素
 */
function updateSubtotal(quantityInput) {
    // 验证并修正数量值：确保数量至少为1
    var num = parseInt(quantityInput.value) || 0;
    if (num < 1) {
        num = 1;
        quantityInput.value = num;
    }
    
    // 获取当前行的价格
    var tr = quantityInput.parentElement.parentElement;
    var price = parseFloat(tr.querySelector('.price').innerText);
    
    // 计算小计
    var total = price * num;
    var subtotalElement = tr.querySelector('.subtotal');
    // 如果是整数显示整数，否则显示两位小数
    subtotalElement.textContent = total % 1 === 0 ? total.toString() : total.toFixed(2);
    
    // 更新购物车总计
    calSum();
}

// 全局变量：全选复选框和总计显示元素
var _all = document.getElementById("all");
var _sum = document.getElementById("sum");

/**
 * 全选功能：点击全选复选框时，选中或取消选中所有商品
 */
if (_all) {
    _all.onclick = function()
    {
        // 获取全选复选框的状态
        var status = this.checked;
        // 获取所有商品复选框
        var _boxes = document.querySelectorAll(".item-checkbox");
        // 将所有商品复选框设置为与全选复选框相同的状态
        _boxes.forEach(function(tag)
        {
            tag.checked = status;
        })
        // 更新总计
        calSum();
    }
}

/**
 * 绑定商品复选框事件：为每个商品复选框绑定点击事件
 */
function bindCheckboxEvents() {
    var _boxes = document.querySelectorAll(".item-checkbox");
    _boxes.forEach(function(tag)
    {
        tag.onclick = function()
        {
            // 判断是否所有的复选框都被选中
            var allBoxes = document.querySelectorAll(".item-checkbox");
            var chs = Array.from(allBoxes).filter(function(item)
            {
                return item.checked == true;
            })
            // 如果所有商品都被选中，则全选复选框也选中
            if (_all) {
                _all.checked = chs.length === allBoxes.length && allBoxes.length > 0;
            }

            // 更新总计
            calSum();
        }
    })
}

/**
 * 计算商品总计：计算所有选中商品的小计总和
 */
function calSum()
{
    var sum = 0;
    // 获取所有商品复选框
    var _boxes = document.querySelectorAll(".item-checkbox");
    // 筛选出被选中的复选框
    var newBoxes = Array.from(_boxes).filter(function(tag)
    {
        return tag.checked == true;
    })

    // 遍历选中的商品，累加小计
    newBoxes.forEach(function(tag)
    {
        var subtotal = tag.parentElement.parentElement.querySelector('.subtotal').innerText;
        sum += parseFloat(subtotal) || 0;
    })

    // 更新总计显示（保留两位小数）
    if (_sum) {
        _sum.innerText = sum.toFixed(2);
    }
}

// 删除当前行
function deleteRow(btn) {
    var tr = btn.parentElement.parentElement;
    var tbody = document.getElementById('cart-body');
    if (tbody && tr.parentElement === tbody) {
        tbody.removeChild(tr);
        // 更新全选状态
        updateAllCheckbox();
        calSum();
    }
}

// 删除选中的商品
function deleteSelected() {
    var checkedBoxes = document.querySelectorAll(".item-checkbox:checked");
    var tbody = document.getElementById('cart-body');
    
    if (checkedBoxes.length === 0) {
        alert('请先选择要删除的商品！');
        return;
    }
    
    checkedBoxes.forEach(function(checkbox) {
        var tr = checkbox.parentElement.parentElement;
        if (tbody && tr.parentElement === tbody) {
            tbody.removeChild(tr);
        }
    });
    
    // 更新全选状态
    updateAllCheckbox();
    calSum();
}

// 清空购物车
function clearCart() {
    if (confirm('确定要清空购物车吗？')) {
        var tbody = document.getElementById('cart-body');
        if (tbody) {
            tbody.innerHTML = '';
            // 更新全选状态
            if (_all) {
                _all.checked = false;
            }
            calSum();
        }
    }
}

// 更新全选复选框状态
function updateAllCheckbox() {
    if (_all) {
        var _boxes = document.querySelectorAll(".item-checkbox");
        var checkedBoxes = Array.from(_boxes).filter(function(item) {
            return item.checked == true;
        });
        _all.checked = checkedBoxes.length === _boxes.length && _boxes.length > 0;
    }
}

/**
 * 添加商品功能：将新商品添加到购物车表格中
 */
function addProduct() {
    // 获取输入框元素
    var nameInput = document.getElementById('product-name');
    var priceInput = document.getElementById('product-price');
    var quantityInput = document.getElementById('product-quantity');
    
    // 获取并处理输入值
    var name = nameInput.value.trim();
    var price = parseFloat(priceInput.value);
    var quantity = parseInt(quantityInput.value) || 1;
    
    // 验证输入：检查商品名称是否为空
    if (!name) {
        alert('请输入商品名称！');
        nameInput.focus();
        return;
    }
    
    // 验证输入：检查价格是否有效（必须是正数）
    if (isNaN(price) || price <= 0) {
        alert('请输入有效的价格！');
        priceInput.focus();
        return;
    }
    
    // 验证输入：检查数量是否有效（必须是正整数）
    if (isNaN(quantity) || quantity <= 0) {
        alert('请输入有效的数量！');
        quantityInput.focus();
        return;
    }
    
    // 计算小计：价格 × 数量
    var subtotal = price * quantity;
    
    // 获取表格tbody元素
    var tbody = document.getElementById('cart-body');
    if (!tbody) {
        return;
    }
    
    // 创建新行，确保与原始商品行结构完全一致
    var newRow = document.createElement('tr');
    
    // 创建复选框单元格
    var checkboxTd = document.createElement('td');
    var checkbox = document.createElement('input');
    checkbox.type = 'checkbox';
    checkbox.className = 'item-checkbox';
    checkboxTd.appendChild(checkbox);
    
    // 创建商品名称单元格
    var nameTd = document.createElement('td');
    nameTd.textContent = name;
    
    // 创建价格单元格
    var priceTd = document.createElement('td');
    priceTd.className = 'price';
    // 如果价格是整数，显示整数；否则显示两位小数
    priceTd.textContent = price % 1 === 0 ? price.toString() : price.toFixed(2);
    
    // 创建数量单元格
    var quantityTd = document.createElement('td');
    var minusBtn = document.createElement('button');
    minusBtn.type = 'button';
    minusBtn.className = 'btn';
    minusBtn.textContent = '-';
    minusBtn.onclick = function() { sub(this); };
    
    var quantityInput = document.createElement('input');
    quantityInput.type = 'text';
    quantityInput.className = 'quantity';
    quantityInput.value = quantity.toString();
    // 绑定输入事件，允许直接输入数量
    quantityInput.oninput = function() {
        updateSubtotal(this);
    };
    // 绑定失焦事件，确保数量有效
    quantityInput.onblur = function() {
        var num = parseInt(this.value) || 1;
        if (num < 1) {
            num = 1;
        }
        this.value = num;
        updateSubtotal(this);
    };
    
    var plusBtn = document.createElement('button');
    plusBtn.type = 'button';
    plusBtn.className = 'btn';
    plusBtn.textContent = '+';
    plusBtn.onclick = function() { add(this); };
    
    quantityTd.appendChild(minusBtn);
    quantityTd.appendChild(document.createTextNode(' '));
    quantityTd.appendChild(quantityInput);
    quantityTd.appendChild(document.createTextNode(' '));
    quantityTd.appendChild(plusBtn);
    
    // 创建小计单元格
    var subtotalTd = document.createElement('td');
    subtotalTd.className = 'subtotal';
    // 如果小计是整数，显示整数；否则显示两位小数
    subtotalTd.textContent = subtotal % 1 === 0 ? subtotal.toString() : subtotal.toFixed(2);
    
    // 创建操作单元格
    var actionTd = document.createElement('td');
    var deleteBtn = document.createElement('button');
    deleteBtn.type = 'button';
    deleteBtn.className = 'btn btn-danger';
    deleteBtn.textContent = '删除';
    deleteBtn.onclick = function() { deleteRow(this); };
    actionTd.appendChild(deleteBtn);
    
    // 组装行
    newRow.appendChild(checkboxTd);
    newRow.appendChild(nameTd);
    newRow.appendChild(priceTd);
    newRow.appendChild(quantityTd);
    newRow.appendChild(subtotalTd);
    newRow.appendChild(actionTd);
    
    // 添加到表格
    tbody.appendChild(newRow);
    
    // 绑定新行的复选框事件
    var newCheckbox = newRow.querySelector('.item-checkbox');
    newCheckbox.onclick = function() {
        var allBoxes = document.querySelectorAll(".item-checkbox");
        var chs = Array.from(allBoxes).filter(function(item) {
            return item.checked == true;
        });
        if (_all) {
            _all.checked = chs.length === allBoxes.length && allBoxes.length > 0;
        }
        calSum();
    };
    
    // 清空输入框
    nameInput.value = '';
    priceInput.value = '';
    quantityInput.value = '1';
    
    // 更新总计
    calSum();
}

/**
 * 结算功能：计算并结算购物车中所有商品
 */
function checkout() {
    // 获取购物车表格body元素
    var tbody = document.getElementById('cart-body');
    if (!tbody) {
        alert('购物车为空！');
        return;
    }
    
    // 获取所有商品行
    var allRows = tbody.querySelectorAll('tr');
    if (allRows.length === 0) {
        alert('购物车为空，请先添加商品！');
        return;
    }
    
    // 计算总价：遍历所有商品行，累加小计
    var totalAmount = 0;
    allRows.forEach(function(tr) {
        var subtotal = parseFloat(tr.querySelector('.subtotal').innerText);
        totalAmount += subtotal;
    });
    
    // 将结算金额显示在总计位置（保留两位小数）
    if (_sum) {
        _sum.innerText = totalAmount.toFixed(2);
    }
    
    // 确认结算：询问用户是否确定要结算
    if (confirm('确定要结算吗？')) {
        // 显示结算成功信息
        alert('结算成功！感谢您的购买！');
        
        // 结算后保留购物车中的商品，不清空
        // 总计已显示结算金额
    }
}

/**
 * 绑定数量输入框事件：为所有数量输入框绑定输入和失焦事件
 * 允许用户直接输入数量，输入时实时更新小计
 */
function bindQuantityInputs() {
    var quantityInputs = document.querySelectorAll('.quantity');
    quantityInputs.forEach(function(input) {
        // 绑定输入事件：用户输入时实时更新小计
        input.oninput = function() {
            updateSubtotal(this);
        };
        // 绑定失焦事件：失去焦点时验证并修正数量值（确保≥1）
        input.onblur = function() {
            var num = parseInt(this.value) || 1;
            if (num < 1) {
                num = 1;
            }
            this.value = num;
            updateSubtotal(this);
        };
    });
}

/**
 * 页面加载完成后的初始化函数
 * 绑定所有事件监听器并初始化总计
 */
window.onload = function () {
    // 绑定每一行的"删除"按钮点击事件
    var deleteButtons = document.querySelectorAll(".btn-danger");
    deleteButtons.forEach(function (btn) {
        if (!btn.onclick || btn.onclick.toString().indexOf('deleteRow') === -1) {
            btn.onclick = function () {
                deleteRow(this);
            };
        }
    });

    // 绑定复选框事件：实现全选和单选功能
    bindCheckboxEvents();
    
    // 绑定数量输入框事件：实现直接输入数量功能
    bindQuantityInputs();

    // 页面加载完成后先计算一次总计
    calSum();
}
