<div>
    <h3>Current Balance: <?= $balance ?></h3>        
    <table>
        <thead>
            <tr>
                <th>Transaction Time</th>
                <th>Symbol</th>
                <th>Shares </th>
                <th>Price</th>
                <th>Total</th>
                <th>Balance</th>
            </tr>
        </thead>
        <tbody>
        <?php foreach ($transactions as $trans): ?>
            <tr>
                <td><?= $trans["created_at"]?></td>
                <td><?= $trans["symbol"] ?>  </td>
                <td><?= $trans["shares"] ?>  </td>
                <td><?= $trans["price"]?>  </td>
                <?php if ($trans["bought"] == 0 && $trans["sold"] == 1) : ?>
                    <td>+<?= number_format($trans["price"] * $trans["shares"] ,2)?></td>
                <?php elseif ($trans["sold"] == 0 && $trans["bought"] == 1) : ?>
                    <td>-<?= number_format($trans["price"] * $trans["shares"] ,2)?></td>
                <?php else : ?>
                    <td>+<?= number_format($trans["price"],2)?></td>
            <?php endif; ?>
            <td><?= number_format($trans["balance"],2)?></td>
            </tr>
            <?php endforeach ?>
        </tbody>
    </table>
</div>