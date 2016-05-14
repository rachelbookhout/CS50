<div>
    <h3>Current Balance: <?= $balance ?></h3>        
    <table id="portfolio">
        <thead>
            <tr>
                <th>Name  </th>
                <th>Symbol  </th>
                <th>Shares  </th>
                <th>Price  </th>
                <th>Total  </th>
            </tr>
        </thead>
        <tbody>
        <?php foreach ($portfolio as $stock): ?>
            <tr>
                <td><?= $stock["name"] ?>  </td>
                <td><?= $stock["symbol"] ?>  </td>
                <td><?= $stock["shares"] ?>  </td>
                <td><?= $stock["price"] ?>  </td>
                <td><?= number_format($stock["price"] * $stock["shares"],2) ?></td>
            </tr>
            <?php endforeach ?>
        </tbody>
    </table>
</div>
